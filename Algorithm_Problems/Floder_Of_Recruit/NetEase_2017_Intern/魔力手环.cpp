//[编程题] 魔力手环
//小易拥有一个拥有魔力的手环上面有n个数字(构成一个环), 当这个魔力手环每次使用魔力的时候就会发生一种奇特的变化：每个数字会变成自己跟后面一个数字的和(最后一个数字的后面一个数字是第一个), 一旦某个位置的数字大于等于100就马上对100取模(比如某个位置变为103, 就会自动变为3).现在给出这个魔力手环的构成，请你计算出使用k次魔力之后魔力手环的状态。
//输入描述 :
//输入数据包括两行：
//第一行为两个整数n(2 ≤ n ≤ 50)和k(1 ≤ k ≤ 2000000000), 以空格分隔
//第二行为魔力手环初始的n个数，以空格分隔。范围都在0至99.
//
//
//输出描述 :
//	输出魔力手环使用k次之后的状态，以空格分隔，行末无空格。
//
//	输入例子 :
//3 2
//1 2 3
//
//输出例子 :
//	8 9 7
//
#include<iostream>
	//#include<map>
#include<algorithm>
	//#include<string>
#include<vector>
	//#include<numeric>
	//#include<cmath>
	//#include<set>
const int MAX_SIZE = 101;
using namespace std;
typedef vector<vector<int>> Matrix;

const int MOD = 100;
vector<int> Magic;
int n; long long int k;

Matrix Matrix_init(MAX_SIZE, vector<int>(MAX_SIZE, 0));
void Make_init(Matrix& Matrix_init) {
	for (int i = 0; i < n; ++i) {
		Matrix_init[i][i] = Matrix_init[i][(i + 1) % n] = 1;
	}
}
/*
k的数量级太大，直接甩你一个TLE
void Solve(vector<int>& Magic) {
int flag = Magic[0];
for (long long int i = 0; i < k; ++i) {
for (int j = 0; j < n; ++j) {
if (j == n - 1)Magic[j] += flag;
else Magic[j] += Magic[j + 1];
if (Magic[j] > 100)Magic[j] %= 100;
}
flag = Magic[0];
}
}
*/
//
//最终的结果相当于 魔力环构成的一维向量[0...n-1]与
//	[1 1 0 0 ...]
//	[0 1 1 0 ...]
//	[0 0 1 1 ...]
//	[...........]
//	[1 0 0.....1]
//	这样的矩阵相乘
//  为了在规定时间内运行，利用矩阵的快速幂优化  
//快速幂blog参考：http ://blog.csdn.net/hikean/article/details/9749391

Matrix Matrix_mul(Matrix a, Matrix b) {
	Matrix temp(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				temp[i][j] += a[i][k] * b[k][j];
				temp[i][j] %= MOD;
			}

		}
	return temp;
}

Matrix Quick_pow(Matrix a, long long int k) {
	long long int N = k;
	Matrix ANS(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
		ANS[i][i] = 1;
	while (N) {
		if (N & 1) {  //即n%2
			ANS = Matrix_mul(ANS, a);
		}
		N = N >> 1;   //即n=n/2
		a = Matrix_mul(a, a);
	}
	return ANS;
}

vector<int> Magic_mul(vector<int> Magic, Matrix BASE) {
	vector<int> temp;
	int flag;
	for (int i = 0; i < n; ++i) {
		flag = 0;
		for (int k = 0; k < n; ++k) {
			flag = (flag + Magic[k] * BASE[i][k]) % MOD;
		}
		temp.push_back(flag);
	}
	return temp;
}

int main() {
	cin >> n;
	cin >> k;
	int item;
	for (int i = 0; i < n; ++i) {
		cin >> item;
		Magic.push_back(item);
	}
	Matrix BASE(n, vector<int>(n, 0));
	Make_init(Matrix_init);
	BASE = Quick_pow(Matrix_init, k);
	Magic = Magic_mul(Magic, BASE);
	for (int i = 0; i < n; ++i) {
		(i == n - 1) ? cout << Magic[i] : cout << Magic[i] << ' ';
	}
	cout << endl;
	return 0;
}
