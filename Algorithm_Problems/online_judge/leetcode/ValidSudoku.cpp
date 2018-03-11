/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
Rule: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool col[9][9] = { false }, row[9][9] = { false }, sub_box[9][9] = { false };

		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[i].size(); ++j)
				if (board[i][j] != '.') {
					int num = board[i][j] - '0' - 1, idx = i / 3 * 3 + j / 3;
					if (col[i][num] || row[j][num] || sub_box[idx][num])
						return false;
					col[i][num] = row[j][num] = sub_box[idx][num] = true;
				}

		return true;
	}
};