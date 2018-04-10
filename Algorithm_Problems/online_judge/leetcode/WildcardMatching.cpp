/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false
*/
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int idx_s = 0, idx_p = 0, idx_star = -1, idx_match = 0;
		while (idx_s < s.size()) {
			if (idx_p < p.size() && (s[idx_s] == p[idx_p] || p[idx_p] == '?')) {
				idx_p++; idx_s++;
			}
			else if (idx_p < p.size() && p[idx_p] == '*') {  // can't match or '?', record pos of *
				idx_star = idx_p;
				idx_p++;
				// record pos of mathced by *, identify with chars matched without *
				idx_match = idx_s;
			}
			else if (idx_star != -1) {  // met * before, match from last pos of *
				idx_p = idx_star + 1;  // trace back to last *
				idx_match++;  // pos of * matched inrease by 1
				idx_s = idx_match;
			}
			else
				return false;
		}
		// skip useless *
		while (idx_p < p.size() && p[idx_p] == '*') {
			idx_p++;
		}
		return idx_p == p.size();
	}

	bool isMatchDp(string s, string p) {
		int s_size = s.size(), p_size = p.size();
		vector<vector<bool>> dp(s_size + 1, vector<bool>(p_size + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= p_size; ++i)
			if (p[i - 1] == '*')
				dp[0][i] = true;
			else
				break;
		for (int i = 1; i <= s_size; ++i)
			for (int j = 1; j <= p_size; ++j) {
				if (p[j - 1] != '*')
					dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
				else
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
			}
		return dp[s_size][p_size];
	}
};

