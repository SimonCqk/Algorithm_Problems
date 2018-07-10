/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
*/
#include<string>
#include<vector>

using namespace std;

class Solution {
public:

	// dp solution: (dp[i][j] represents whether s3 is interleaving by s1[i] and s2[j])
	// - if s1 & s2 & s3 all empty, considered as interleaving.
	// - if s1 is empty, dp[i][j] = (dp[i][j-1] && s2[j-1]==s3[i+j-1])
	// - if s2 is empty, dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i+j-1])
	// - if s1 & s2 are both not empty, dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1]==s3[i+j-1])
	bool isInterleave(string s1, string s2, string s3) {
		if (s3.size() != (s1.size() + s2.size()))
			return false;
		vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
		for (int i = 0; i <= s1.size(); ++i)
			for (int j = 0; j <= s2.size(); ++j) {
				if (i == 0 && j == 0)
					dp[i][j] = true;
				else if (i == 0)
					dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
				else if (j == 0)
					dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
				else
					dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		return dp[s1.size()][s2.size()];
	}

	/*bool isInterleave(string s1, string s2, string s3) {
		if (s3.size() != (s1.size() + s2.size()))
			return false;
		vector<bool> flags(s3.size(), false);
		int s1_idx = 0, s2_idx = s2.size() - 1, s3_s1 = 0, s3_s2 = s3.size() - 1;
		bool order = true;
		while (s1_idx < s1.size() && s3_s1 < s3.size()) {
			if (s3[s3_s1] == s1[s1_idx] && !flags[s3_s1]) {
				flags[s3_s1] = true;
				++s1_idx;
				++s3_s1;
			}
			else {
				++s3_s1;
			}
		}
		if (s1_idx < s1.size())
			return false;
		while (s2_idx >= 0 && s3_s2 >= 0) {
			if (s3[s3_s2] == s2_idx && !flags[s3_s2]) {
				flags[s3_s2] = true;
				--s2_idx;
				--s3_s2;
			}
			else {
				--s3_s2;
			}
		}
		if (s2_idx > 0)
			return false;
		for (bool each : flags)
			if (!each)return false;
		return true;
	}*/
};