/*
 实现一个函数来匹配包含'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而
 '*'表示它前面的字符可以出现任意次（含0次）。
 例如"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"不匹配。
 */

#include<string>
#include<iostream>
#include<vector>

using namespace std;

/*
 纯递归版本，复杂匹配模式非非非常耗时
*/
bool IsMatch(const string& str, const string& pattern) {
	if (pattern.empty())
		return str.empty();
	if (pattern[1] == '*') {
		if (pattern[0] == str[0] || (pattern[0] == '.' && !str.empty()))
			return IsMatch(str.substr(1), pattern.substr(2)) ||
			IsMatch(str.substr(1), pattern) ||
			IsMatch(str, pattern.substr(2));
		else
			return IsMatch(str, pattern.substr(2));
	}
	if (pattern[0] == str[0] || (pattern[0] == '.' && !str.empty()))
		return IsMatch(str.substr(1), pattern.substr(1));
	return false;
}

/*
 动态规划版本，空间换时间
 https://discuss.leetcode.com/topic/17852/9-lines-16ms-c-dp-solutions-with-explanations
 分三种情况：
 dp[i][j] = true代表str[0...i]与pattern[0...j]成功匹配
 P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
 P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
 P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.
*/

bool IsMatchDp(const string& str, const string& pattern) {
	int ssize = str.size(), psize = pattern.size();
	vector<vector<bool>> dp(ssize + 1, vector<bool>(psize + 1, false));
	dp[0][0] = true;
	for (int i = 0; i <= ssize; ++i)
		for (int j = 1; j <= psize; ++j) {
			if (pattern[j - 1] == '*')
				dp[i][j] = dp[i][j - 2] || (i > 0 && str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.') && dp[i - 1][j];
			else
				dp[i][j] = i > 0 && dp[i - 1][j - 1] &&  (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.');
		}
	return dp[ssize][psize];
}



int main() {
	string str = "aaaaaaaaaaaaab";
	string pattern = "a*a*a*a*a*a*a*a*a*a*c";
	cout << IsMatchDp(str, pattern) << endl;
	return 0;
}