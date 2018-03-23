/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach

the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

*/
#include<vector>
#include<algorithm>

using std::vector;

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m <= 1 && n <= 1)
			return 1;
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j) {
				if (!i || !j)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		return dp[m - 1][n - 1];
	}
};

/*
 a better solution:
 vector<vector<int> > path(m, vector<int> (n, 1));
 for (int i = 1; i < m; i++)
	for (int j = 1; j < n; j++)
		path[i][j] = path[i - 1][j] + path[i][j - 1];
 return path[m - 1][n - 1];
*/