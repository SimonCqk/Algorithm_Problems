/*
  在一个m*n的棋盘上每一格都放有一个礼物，每个礼物都有一定的价值(价值大于0)
  可以从棋盘的左上角开始拿格子里的礼物，并每次向左或者向下移动一个，直到到达棋盘的
  右下角。给定一个棋盘，请计算最多能拿到多少价值的礼物？
 */

 // 典型的动态规划思路
 // f(i,j)代表行至gifts[i][j]时的最大价值，那么有
 // f(i,j)=max(f[i-1][j],f[i][j-1])+gifts[i][j]
#include<algorithm>
#include<vector>

using namespace std;

// 空间复杂度为O(n^2)
int GetMaxGiftsValue(const vector<vector<int>>& gifts) {
	if (gifts.empty() || gifts[0].empty())  // 假设gifts保证是一个Matrix
		return 0;
	int rows = gifts.size(), cols = gifts[0].size();
	vector<vector<int>> dp(rows, vector<int>(rows, 0));
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j) {
			int left = 0, up = 0;
			if (i > 0)
				left = dp[i - 1][j];
			if (j > 0)
				up = dp[i][j - 1];
			dp[i][j] = std::max(left, up) + gifts[i][j];
		}
	return dp[rows - 1][cols - 1];
}

// 优化：每次求dp[i,j]，实际只用到了dp[i-1,j]和dp[i,j-1]
// 那么空间复杂度可以降为O(n)
// 对于f(i,j): 前j个数字dp[0...j-1]分别为f(i,0),f(i,1)...f(i,j-1),
// 第j个数字往后是上一轮的旧值，即f(i-1,j),f(i-1,j+1)...f(i-1,n-1).
int GetMaxGiftsValue_Optimized(const vector<vector<int>>& gifts) {
	if (gifts.empty() || gifts[0].empty())  // 假设gifts保证是一个Matrix
		return 0;
	int rows = gifts.size(), cols = gifts[0].size();
	vector<int> dp(cols, 0); 
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j) {
			int left = 0, up = 0;
			if (i > 0)
				left = dp[j];
			if (j > 0)
				up = dp[j - 1];
			dp[j] = std::max(left, up) + gifts[i][j];
		}
	return dp[cols - 1];
}

int main() {
	vector<vector<int>> gifts{
		{1,10,3,8},
		{12,2,9,8},
		{5,7,4,11},
		{3,7,16,5}
	};
	std::printf("%d\n", GetMaxGiftsValue(gifts));
	std::printf("%d\n", GetMaxGiftsValue_Optimized(gifts));
	return 0;
}