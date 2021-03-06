/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/
#include<vector>

using std::vector;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
		vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
		dp[0][1] = 1;
		for (int i = 1; i <= rows; ++i)
			for (int j = 1; j <= cols; ++j)
				if (!obstacleGrid[i - 1][j - 1])
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

		return dp[rows][cols];
	}
};