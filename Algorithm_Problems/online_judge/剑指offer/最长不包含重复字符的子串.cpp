/*
  请从字符串中找出一个最长的不包含重复字符的子串。计算该字符串的长度，
  假设该字符串中只包含'a'~'z'的字符。
*/
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int LongestNonrepeatingSubstring(const string& str) {
	int size = str.size();
	vector<int> dp(size, 0);
	dp[0] = 1;
	vector<int> map(26, -1); // 记录对应字符上次出现的位置
	int max_len = 0;
	map[str[0] - 'a'] = 0;
	for (int i = 1; i < size; ++i) {
		int pre = map[str[i] - 'a'];
		if (pre<0 || (i - pre)>dp[i - 1]) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			max_len = std::max(max_len, dp[i - 1]);
			dp[i] = i - pre;
		}
		map[str[i] - 'a'] = i;
	}
	max_len = std::max(max_len, dp[size - 1]);
	return max_len;
}

int main() {
	string s = "arabcacfr";
	std::printf("%d\n", LongestNonrepeatingSubstring(s));
	return 0;
}