/*
设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左,右,上,下移动一格。
如果一条路径经过了矩阵的某一格，则不能再次进入。

回溯法经典题型

*/
#include<vector>
#include<string>
#include<iostream>
#include<stack>

using namespace std;

/*
 递归实现回溯法
*/

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
	if (matrix.empty() || path.empty() || rows < 1 || cols < 1)
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

/*
 栈模拟递归实现回溯法
*/

bool HasPath_NoRecursive(const vector<vector<char>>& matrix, const string& path) {
	if (matrix.empty() || path.empty())
		return false;
	int rows = matrix.size(), cols = matrix[0].size();
	stack<pair<int, int>> steps;
	//在矩阵中找到路径的起点
	for (int i = 0, found = 0; i < rows && !found; ++i)
		for (int j = 0; j < cols; ++j)
			if (matrix[i][j] == path[0]) {
				steps.push({ i,j });
				found = 1;
				break;
			}
	//判断是否有起点存在
	if (steps.empty())
		return false;
	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
	auto cur = steps.top();
	int index = 1;
	while (cur.first < rows&&cur.second < cols && !visited[cur.first][cur.second] && steps.size() < path.size()) {
		visited[cur.first][cur.second] = true;
		if (cur.first - 1 >= 0 && !visited[cur.first - 1][cur.second] && matrix[cur.first - 1][cur.second] == path[index]) {
			steps.push({ cur.first - 1,cur.second });
			++index;
		}
		else if (cur.first + 1 < rows && !visited[cur.first + 1][cur.second] && matrix[cur.first + 1][cur.second] == path[index]) {
			steps.push({ cur.first + 1,cur.second });
			++index;
		}
		else if (cur.second - 1 >= 0 && !visited[cur.first][cur.second - 1] && matrix[cur.first][cur.second - 1] == path[index]) {
			steps.push({ cur.first,cur.second - 1 });
			++index;
		}
		else if (cur.second + 1 < cols && !visited[cur.first][cur.second + 1] && matrix[cur.first][cur.second + 1] == path[index]) {
			steps.push({ cur.first,cur.second + 1 });
			++index;
		}
		else {
			--index;
			if (index < 1)
				return false;
			steps.pop();
			visited[steps.top().first][steps.top().second] = false;
		}
		cur = steps.top();
	}
	return steps.size() == path.size();
}

int main() {
	vector<vector<char>> matrix = {
		{'a','b','t','g'},
		{'c','f','c','s'},
		{'j','d','e','h'}
	};
	string path = "abtgggg";
	cout << HasPath_NoRecursive(matrix, path) << endl;
	path = "bfce";
	cout << HasPath_NoRecursive(matrix, path) << endl;
	return 0;
}