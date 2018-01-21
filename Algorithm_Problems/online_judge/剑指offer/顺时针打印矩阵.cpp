/*
输入一个矩阵，按照从外向里以顺时针的顺序依此打印出每一个数字。
*/
#include<vector>

using namespace std;

void PrintMatirxClockwisely(const vector<vector<int>>& matrix) {
	if (matrix.size() == 0)
		return ;
	int row = matrix.size(), col = matrix[0].size();
	int up = 0, down = row - 1, left = 0, right = col - 1, count = 0;
	vector<int> ans;
	// int row = matrix.size(), col = matrix[0].size();
	int total = row * col;
	while (true) { // judge count with n*n inside while body
		for (int i = left; i <= right; ++i) { // do not `while(count<=n*n)`
			ans.push_back(matrix[up][i]);       // or it will run out of time
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
	for (const int& i : ans)
		std::printf("%d ", i);
	std::printf("\n");
}

int main() {
	vector<vector<int>> matrix{
	{1,2,3,4},
	{10,11,12,5},
	{9,8,7,6},
	};
	PrintMatirxClockwisely(matrix);
	return 0;
}