#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

/*
输入:
输入描述 输入是一个NxK的二维矩阵。N表示有几个方块，K表示有多少种颜色。
这个矩阵cost[0][0]表示方块0被涂成0号颜色的花费。 输入的第一行是N,K 接下来是每一行的数据
输出:
最小的花费
输入范例:
4 3
2 3 2
9 1 4
7 8 1
2 8 3
输出范例:
6
*/

/** 请完成下面这个函数，实现题目要求的功能 **/
/** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
int minCost(vector<vector<int>>& costs)
{
	if (costs.empty() || costs[0].empty())
		return 0;
	vector<bool> color_hash(costs[0].size(), false);
	int min=(1<<10);
	for (int i = 0; i < costs[0].size(); ++i) {
		vector<int> dp(costs.size(), (1<<31));
		dp[0] = costs[0][i];
		color_hash[0] = true;
		for (int j = 1; j < costs.size(); ++j) {
			// 当前方块最小的与相邻不同色的花费
			int cur_min = 1<<31;
			int color_inex = 0;
			for (int n = 0; n < costs[j].size();++n) {
				if (!color_hash[j - 1] && costs[j][n] < cur_min) {
					cur_min = costs[j][n];
					color_inex = n;
				}
			}
			// 选定颜色并着色
			color_hash[color_inex] = true;
			dp[j] = (cur_min < dp[j]) ? cur_min : dp[j];
		}
		// 当前最小花费的和
		int sum = 0;
		for (auto item : dp)
			sum += item;
		min = (sum < min) ? sum : min;
		dp.resize(costs.size(), (1 << 31));
		color_hash.resize(costs[0].size(), false);
	}
	return min;
}

int main()
{
	int N, K;
	int cost;
	vector<vector<int> > costs;
	string s;
	istringstream is;

	getline(cin, s);
	is.str(s);
	is >> N >> K;
	for (int i = 0; i < N; i++)
	{
		vector<int> t;
		getline(cin, s);
		is.clear();
		is.str(s);
		for (int j = 0; j < K; j++) {
			is >> cost;
			t.push_back(cost);
		}
		costs.push_back(t);
	}
	cout << minCost(costs) << endl;
	return 0;
}