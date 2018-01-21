/*
在一个二维数组中，每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

// 从右上角或者左下角开始查找，逐步缩小查找范围
// 不能从左上或者右下开始，范围会重叠

class Solution {
public:
	bool Find(int target, vector<vector<int>> matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		// 判断是否为矩阵
		for (const auto& each : matrix) {
			if (each.size() != col)
				return false;
		}
		for (int i = 0, j = col - 1; i >= 0 && i < row;){
			if (target == matrix[i][j])
				return true;
			else if (target < matrix[i][j])
				i--;
			else			
				j++;
		}
		return false;
	}
};