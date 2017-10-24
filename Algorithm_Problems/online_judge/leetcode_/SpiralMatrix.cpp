/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the
matrix in spiral order.

For example,
Given the following matrix:

[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>> &matrix) {
		if (matrix.size() == 0)
			return {};
		int row = matrix.size(), col = matrix[0].size();
		int up = 0, down = row - 1, left = 0, right = col - 1, count = 0;
		vector<int> ans;
		// int row = matrix.size(), col = matrix[0].size();
		int total = row * col;
		while (true) {
			for (int i = left; i <= right; ++i) {
				ans.push_back(matrix[up][i]);
				++count;
			}
			if (count >= total)
				break;
			++up;
			for (int i = up; i <= down; ++i) {
				ans.push_back(matrix[i][right]);
				++count;
			}
			if (count >= total)
				break;
			--right;
			for (int i = right; i >= left; --i) {
				ans.push_back(matrix[down][i]);
				++count;
			}
			if (count >= total)
				break;
			--down;
			for (int i = down; i >= up; --i) {
				ans.push_back(matrix[i][left]);
				++count;
			}
			if (count >= total)
				break;
			++left;
		}
		return ans;
	}
};