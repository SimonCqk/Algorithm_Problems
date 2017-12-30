/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "a*") ¡ú true
isMatch("aa", ".*") ¡ú true
isMatch("ab", ".*") ¡ú true
isMatch("aab", "c*a*b") ¡ú true

*/
#include<string>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int ssize = str.size(), psize = pattern.size();
		vector<vector<bool>> dp(ssize + 1, vector<bool>(psize + 1, false));
		dp[0][0] = true;
		for (int i = 0; i <= ssize; ++i)
			for (int j = 1; j <= psize; ++j) {
				if (pattern[j - 1] == '*')
					dp[i][j] = dp[i][j - 2] || (i > 0 && str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.') && dp[i - 1][j];
				else
					dp[i][j] = i > 0 && dp[i - 1][j - 1] && (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.');
			}
		return dp[ssize][psize];
	}
};