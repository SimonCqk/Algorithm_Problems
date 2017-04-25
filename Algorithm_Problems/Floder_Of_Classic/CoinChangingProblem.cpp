//DP:coin changing problem
//c1,c2...cm元的m种硬币，求支付n元时所需硬币的最少枚数
//各面值的硬币可重复使用任意次

//用一维数组T[j]表示支付j元时的最少枚数
//T[j]=min(T[j],T[j-C[i]]+1)

#include<iostream>
#include<algorithm>
using namespace std;
static const int CoinMax = 20;
static const int NMAX = 50000;
static const int INIT = (1 << 20);

int main() {
	int T[NMAX + 1];
	int C[CoinMax + 1];
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> C[i];
	}
	for (int i = 0; i <= NMAX; ++i)T[i] = INIT;
	T[0] = 0;
	for (int i = 1; i <= m; ++i)
		for (int j = C[i]; j <= n; ++j) {
			T[j] = min(T[j], T[j - C[i]] + 1);
		}
	cout << T[n] << endl;
	return 0;
}