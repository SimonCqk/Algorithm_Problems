/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle

containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 6.
*/

#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty())
			return 0;
		int max_rec = 0, cur_left, cur_right;
		int rows = matrix.size(), cols = matrix[0].size();
		// rectangle = (right[i,j]-left[i,j]) * height[i,j].
		vector<int> left(cols, 0), right(cols, cols), height(cols, 0);

		for (int i = 0; i < rows; ++i) {
			cur_left = 0, cur_right = cols;
			// compute heights
			for (int j = 0; j < cols; ++j) {
				if (matrix[i][j] == '1')
					++height[j];
				else
					height[j] = 0;
			}
			// compute lefts
			for (int j = 0; j < cols; ++j) {
				if (matrix[i][j] == '1')
					left[j] = std::max(left[j], cur_left);
				else {
					left[j] = 0; cur_left = j + 1;
				}
			}
			// compute rights
			for (int j = cols - 1; j >= 0; --j) {
				if (matrix[i][j] == '1')
					right[j] = std::min(right[j], cur_right);
				else {
					right[j] = cols; cur_right = j;  // set right[j] to its maximum value
				}
			}

			for (int j = 0; j < cols; ++j)
				max_rec = std::max(max_rec, height[j] * (right[j] - left[j]));
		}
		return max_rec;
	}
};

int main() {
	vector<vector<char>> matrix{
		{'1','0','1','0','0'},
		{'1','0','1','1','1'},
		{'1','1','1','1','1'},
		{'1','0','0','1','0'}
	};
	Solution s;
	int ans = s.maximalRectangle(matrix);
	return 0;
}