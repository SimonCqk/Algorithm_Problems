/*
Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting
some (can be none) of the characters without disturbing the relative positions of the remaining characters.
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int s_size = s.size(), t_size = t.size();
		vector<vector<int>> dp(t_size + 1, vector<int>(s_size + 1, 0));
		for (int i = 0; i <= s_size; ++i)
			dp[0][i] = 1;  // empty string included
		for (int i = 0; i < t_size; ++i)
			for (int j = 0; j < s_size; ++j) {
				if (s[j] == t[i])
					dp[i + 1][j + 1] = dp[i][j] + dp[i + 1][j];
				else
					dp[i + 1][j + 1] = dp[i + 1][j];
			}
		return dp[t_size][s_size];
	}
};