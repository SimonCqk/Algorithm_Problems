/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell,

where "adjacent" cells are those horizontally or vertically neighboring.

The same letter cell may not be used more than once.

Example:

board =
[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/
#include<vector>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty() || board.empty())
			return false;
		int rows = board.size(), cols = board[0].size();
		vector<vector<bool>> visited(rows, vector<bool>(cols, false));
		int cur_len = 0;
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j) {
				if (existCore(board, rows, cols, i, j, word, cur_len, visited))
					return true;
			}
		return false;
	}
	bool existCore(const vector<vector<char>>& board, const int& rows, const int& cols,
		int row, int col, const string& path, int& cur_len, vector<vector<bool>>& visited) {
		if (cur_len == path.size())
			return true;
		bool has_path = false;
		if (row >= 0 && row < rows&&col >= 0 && col < cols&&board[row][col] == path[cur_len] && !visited[row][col]) {
			++cur_len;
			visited[row][col] = true;
			has_path = existCore(board, rows, cols, row, col - 1, path, cur_len, visited)  // 检查左边
				|| existCore(board, rows, cols, row - 1, col, path, cur_len, visited)  // 检查上边
				|| existCore(board, rows, cols, row, col + 1, path, cur_len, visited)  // 检查右边
				|| existCore(board, rows, cols, row + 1, col, path, cur_len, visited);  // 检查下边
			if (!has_path) {  // 后面的路径不合题意，回溯
				--cur_len;
				visited[row][col] = false;
			}
		}
		return has_path;
	}
};