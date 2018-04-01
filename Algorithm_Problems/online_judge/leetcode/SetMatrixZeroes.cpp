/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
#include<vector>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int rows = matrix.size(), cols = matrix[0].size();
		bool row_is_0 = false;
		// first phase: use first element of each row & column to store 0 or not.
		// "row_is_0" set to be denoted as its original value is 0.
		for (int i = 0; i < rows; ++i) {
			if (!matrix[i][0])
				row_is_0 = true;
			for (int j = 1; j < cols; ++j)
				if (!matrix[i][j])
					matrix[i][0] = matrix[0][j] = 0;
		}
		// second phase: set zeros from bottom to up.
		for (int i = rows - 1; i >= 0; --i) {
			for (int j = cols - 1; j >= 1; --j) {
				if (!matrix[i][0] || !matrix[0][j])
					matrix[i][j] = 0;
			}
			if (row_is_0)
				matrix[i][0] = 0;
		}
	}
};