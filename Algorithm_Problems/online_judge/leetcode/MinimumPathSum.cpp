/*
Given a m x n grid filled with non-negative numbers, find a path from top left to

bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
[[1,3,1],
[1,5,1],
[4,2,1]]
Given the above grid map, return 7. Because the path 1¡ú3¡ú1¡ú1¡ú1 minimizes the sum.
*/
#include<vector>
#include<algorithm>

using std::vector;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int rows = grid.size(), cols = grid[0].size();
		vector<vector<int>> dp(rows, vector<int>(cols, 0));
		dp[0][0] = grid[0][0];
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j) {
				if (!i && !j)
					continue;
				else if (!i)
					dp[i][j] = dp[i][j - 1] + grid[i][j];
				else if (!j)
					dp[i][j] = dp[i - 1][j] + grid[i][j];
				else
					dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		return dp[rows - 1][cols - 1];
	}
};