/*
[编程题] 工作安排
现在有n位工程师和6项工作(编号为0至5)，现在给出每个人能够胜任的工作序号表(用一个字符串表示，
比如：045，表示某位工程师能够胜任0号，4号，5号工作)。现在需要进行工作安排，
每位工程师只能被安排到自己能够胜任的工作当中去，两位工程师不能安排到同一项工作当中去。
如果两种工作安排中有一个人被安排在的工作序号不一样就被视为不同的工作安排，现在需要计算出有多少种不同工作安排计划。
输入描述:
输入数据有n+1行：
第一行为工程师人数n(1 ≤ n ≤ 6)
接下来的n行，每行一个字符串表示第i(1 ≤ i ≤ n)个人能够胜任的工作(字符串不一定等长的)


输出描述:
输出一个整数，表示有多少种不同的工作安排方案

输入例子:
6
012345
012345
012345
012345
012345
012345

输出例子:
720
*/

//数据量不大，直接用DFS暴力枚举
//数据大了就GG了...

#include<iostream>
#include<cstring>
#include<string>
using namespace std;
bool workable[6][6];
bool arranged[6];			//记录工作是否已被安排，避免继续递归时重复访问.
int n;
int dfs(int now) {
	int ans = 0;
	for (int i = 0; i < 6; i++) {
		if (workable[now][i] && !arranged[i]) {
			arranged[i] = true;
			if (now == 0)
				++ans;
			else
				ans += dfs(now - 1);
			arranged[i] = false;
		}
	}
	return ans;
}
int main() {
	cin >> n;
	memset(workable, 0, sizeof(workable));
	memset(arranged, 0, sizeof(arranged));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int s_size = s.size();
		for (int j = 0; j < s_size; ++j)
			workable[i][s[j] - '0'] = true;
	}
	cout << dfs(n - 1) << endl;
	return 0;
}
