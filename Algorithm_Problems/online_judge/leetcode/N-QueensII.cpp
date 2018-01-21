/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

class Solution {
public:
	int totalNQueens(int n) {
		auto ans = solveNQueens(n);
		return ans.size();
	}
	std::vector<std::vector<std::string>> solveNQueens(int n) {
		std::vector<std::vector<std::string>> solutions;
		std::vector<std::string> solution(n, std::string(n, '.'));
		solve(solutions, solution, 0, n);
		return solutions;
	}
	void solve(std::vector<std::vector<std::string> > &solutions,
		std::vector<std::string> &solution, const int& row, const int &n) {
		if (row == n) {
			solutions.push_back(solution);
			return;
		}
		for (int col = 0; col != n; ++col)
			if (isValid(solution, row, col, n)) {
				solution[row][col] = 'Q';
				solve(solutions, solution, row + 1, n);
				solution[row][col] = '.';
			}
	}
	bool isValid(const std::vector<std::string>& solu, const int& row, const int& col, const int& n) {
		assert(row < n && col < n);
		//check row | column 
		for (int i = 0; i < n; ++i) {
			if (i != col&&solu[row][i] == 'Q')
				return false;
			if (i != row&&solu[i][col] == 'Q')
				return false;
		}
		// check left-up diagonal
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
			if (solu[i][j] == 'Q')
				return false;
		}
		// check right-up diagonal
		for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
			if (solu[i][j] == 'Q')
				return false;
		}
		return true;
	}
};