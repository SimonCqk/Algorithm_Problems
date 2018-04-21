/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
	   [2],
	  [3,4],
	 [6,5,7],
	[4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int rows = triangle.size(), last_cols = triangle[triangle.size() - 1].size();
		vector<int> dp(last_cols, 0), tmp;
		dp[0] = triangle[0][0];
		for (int i = 1; i < rows; ++i) {
			int cur_rows = triangle[i].size();
			tmp = dp;
			for (int j = 0; j < cur_rows; ++j) {
				if (j == 0)
					dp[j] = tmp[j] + triangle[i][j];
				else if (j > 0 && j < cur_rows - 1)
					dp[j] = std::min(tmp[j - 1], tmp[j]) + triangle[i][j];
				else
					dp[j] = tmp[j - 1] + triangle[i][j];
			}
		}
		int min = dp[0];
		for (auto& each : dp)
			min = std::min(min, each);
		return min;
	}
};
