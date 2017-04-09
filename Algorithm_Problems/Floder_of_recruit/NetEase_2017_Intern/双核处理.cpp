//[编程题] 双核处理
//一种双核CPU的两个核能够同时的处理任务，现在有n个已知数据量的任务需要交给CPU处理，假设已知CPU的每个核1秒可以处理1kb，
//每个核同时只能处理一项任务。n个任务可以按照任意顺序放入CPU进行处理，
//现在需要设计一个方案让CPU处理完这批任务所需的时间最少，求这个最小的时间。
//输入描述 :
//输入包括两行：
//第一行为整数n(1 ≤ n ≤ 50)
//第二行为n个整数length[i](1024 ≤ length[i] ≤ 4194304)，表示每个任务的长度为length[i]kb，每个数均为1024的倍数。
//
//
//输出描述 :
//输出一个整数，表示最少需要处理的时间
//
//输入例子 :
//5
//3072 3072 7168 3072 1024
//
//输出例子 :
//	9216
//

#include<iostream>
//#include<map>
#include<algorithm>
//#include<string>
#include<vector>
#include<numeric>
//#include<cmath>
//#include<set>
using namespace std;
const int MAX_SIZE = 51;
vector<int> Length_n;

int n;

//使得max(cpu_one_time,cpu_two_time)最小
//   =====> 01 bag 模型：
//体积为sum/2，共有n个物体，代价为t[i]，价值也是t[i]，尽量多的装
//0-1 bag 思路补充：
//有N件物品和一个容量为V的背包。第i件物品的费用是c[i],价值是w[i],求解将哪些物品放入背包可使价值总和最大
//特点： 每一件物品仅有一件，能够选择放或者不放。 
//定义状态：F[i][v]:表示前i件物品恰好放入一个容量为v的背包能够获得的最大的价值 
//转移方程：F[i][v]=max(F[i-1][v],F[i-1][v-c[i]]+w[i]]); 
//优化空间复杂度： 以上求法时间和空间复杂度均为O(V*N),时间复杂度不能在优化了，然而空间复杂度能够进一步优化
//我们这样考虑：仅仅用一个数组F[0..V],保证第i次循环结束结束后F[v]表示的是就是定义的状态F[i][v]


int solve(vector<int>& Len, int sum) {
	int halfsum = sum >> 1;
	vector<int> DP(halfsum + 1, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = halfsum; j >= Len[i]; --j)
			DP[j] = max(DP[j], DP[j - Len[i]] + Len[i]);
	}
	return DP[halfsum];
}

int main() {
	cin >> n; int item;
	for (int i = 0; i < n; ++i) {
		cin >> item;
		Length_n.push_back(item / 1024);
	}
	//sort(Length_n.begin(), Length_n.end());
	int SUM = accumulate(Length_n.begin(), Length_n.end(), 0);
	int result = max(solve(Length_n, SUM), SUM - solve(Length_n, SUM));
	cout << result * 1024 << endl;
	return 0;
}
