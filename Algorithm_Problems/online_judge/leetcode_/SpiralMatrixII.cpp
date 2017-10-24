/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
*/

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<int> seed;
		for (int i = 1; i <= n*n; ++i) {
			seed.push_back(i);
		}
		int up = 0, down = n - 1, left = 0, right = n - 1;
		vector<vector<int>> ans(n, vector<int>(n, 0));
		int count = 0;
		while (true) {                              // judge count with n*n inside while body
			for (int i = left; i <= right; ++i) {   // do not `while(count<=n*n)`
				ans[up][i] = seed[count++];         // or it will run out of time
			}
			if (count >= n*n)
				break;
			++up;
			for (int i = up; i <= down; ++i) {
				ans[i][right] = seed[count++];
			}
			if (count >= n*n)
				break;
			--right;
			for (int i = right; i >= left; --i) {
				ans[down][i] = seed[count++];
			}
			if (count >= n*n)
				break;
			--down;
			for (int i = down; i >= up; --i) {
				ans[i][left] = seed[count++];
			}
			if (count >= n*n)
				break;
			++left;
		}
		return ans;
	}
};