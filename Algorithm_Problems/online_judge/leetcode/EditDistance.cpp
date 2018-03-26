/*
Given two words word1 and word2, find the minimum number of steps required

to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

// solution: https://leetcode.com/problems/edit-distance/discuss/25846/20ms-Detailed-Explained-C++-Solutions-(O(n)-Space)
class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.size(), m = word2.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		// edge cases: convert empty string to another which is not empty
		for (int i = 1; i <= n; ++i)
			dp[i][0] = i;
		for (int j = 1; j <= m; ++j)
			dp[0][j] = j;
		/*
		general cases:
		Replace word1[i - 1] by word2[j - 1](dp[i][j] = dp[i - 1][j - 1] + 1 (for replacement));
		Delete word1[i - 1] and word1[0..i - 2] = word2[0..j - 1](dp[i][j] = dp[i - 1][j] + 1 (for deletion));
		Insert word2[j - 1] to word1[0..i - 1] and word1[0..i - 1] + word2[j - 1] = word2[0..j - 1]
		(dp[i][j] = dp[i][j - 1] + 1 (for insertion)).
		*/
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = std::min(dp[i - 1][j - 1] + 1, std::min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
			}
		return dp[n][m];
	}
};