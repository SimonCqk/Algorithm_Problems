/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
Given target = 3, return true.
*/
#include<vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())
			return false;
		int rows = matrix.size(), cols = matrix[0].size();
		for (int i = 0; i < rows; ++i) {
			if (i + 1 < rows&&matrix[i + 1][0] <= target)
				continue;
			for (int j = 0; j < cols; ++j)
				if (matrix[i][j] == target)
					return true;
		}
		return false;
	}
};