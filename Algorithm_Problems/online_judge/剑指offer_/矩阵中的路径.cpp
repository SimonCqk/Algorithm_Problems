/*
设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左,右,上,下移动一格。
如果一条路径经过了矩阵的某一格，则不能再次进入。

回溯法经典题型

*/
#include<vector>
#include<string>
#include<iostream>

using namespace std;

bool HasPathCore(const vector<vector<char>>& matrix, int rows, int cols, int row, int col, const string& path, int& path_len, vector<vector<bool>>& visited) {
	if (path_len == path.size())
		return true;
	bool haspath = false;
	if (row >= 0 && row < rows&&col >= 0 && col < cols&&matrix[row][col] == path[path_len] && !visited[row][col]) {
		++path_len;
		visited[row][col] = true;
		haspath = HasPathCore(matrix, rows, cols, row, col - 1, path, path_len, visited)  // 检查左边
			|| HasPathCore(matrix, rows, cols, row - 1, col, path, path_len, visited)  // 检查上边
			|| HasPathCore(matrix, rows, cols, row, col + 1, path, path_len, visited)  // 检查右边
			|| HasPathCore(matrix, rows, cols, row + 1, col, path, path_len, visited);  // 检查下边
		if (!haspath) {  // 后面的路径不合题意，回溯
			--path_len;
			visited[row][col] = false;
		}
		return haspath;
	}
}


bool HasPath(const vector<vector<char>>& matrix, int rows, int cols, const string& path) {
	if (rows < 1 || cols < 1)
		return false;
	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
	int path_len = 0;
	for (int row = 0; row < rows; ++row)
		for (int col = 0; col < cols; ++col) {
			if (HasPathCore(matrix, rows, cols, row, col, path, path_len, visited))
				return true;
		}
	return false;
}


int main() {
	vector<vector<char>> matrix = {
		{'a','b','t','g'},
		{'c','f','c','s'},
		{'j','d','e','h'}
	};
	string path = "bfce";
	cout << HasPath(matrix, 3, 4, path) << endl;
	return 0;
}