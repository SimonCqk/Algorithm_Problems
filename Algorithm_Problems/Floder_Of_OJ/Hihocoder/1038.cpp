#include<iostream>
#include<algorithm>
//#include<string>
#define MAX_Coupon 100001
#define MAX_Gift 501
using namespace std;

/*
//二维数组版本
//int Best[MAX_Gift][MAX_Coupon]
int Solve(int Gift_num, int Coupon_num, long long  Need[], int Value[], int Best[][MAX_Coupon]) {
	int i, j;
	for (j = 0; j < Coupon_num; ++j)Best[0][j] = 0;
	for (i = 1; i <= Gift_num; ++i) {
		for (j = 0; j <=Coupon_num; ++j) {
			if (j < Need[i])Best[i][j] = Best[i - 1][j];
			else Best[i][j] = max(Best[i-1][j], Best[i-1][j - Need[i]] + Value[i]);
		}
	}
	return Best[Gift_num][Coupon_num];

}
*/
int Solve(int Gift_num, int Coupon_num, long long  Need[], int Value[], int Best[]) {
	int i, j;
	for (j = 0; j < Coupon_num; ++j)Best[j] = 0;
	for (i = 1; i <= Gift_num; ++i) {
		for (j = Coupon_num; j >= Need[i]; --j) {
			Best[j] = max(Best[j], Best[j - Need[i]] + Value[i]);
		}
	}
	return Best[Coupon_num];

}


long long Need[MAX_Gift];
int Value[MAX_Gift], Best[MAX_Coupon];
int main() {
	int Gift_num, Coupon_num;
	cin >> Gift_num >> Coupon_num;
	for (int i = 1; i <= Gift_num; ++i) {
		cin >> Need[i] >> Value[i];
	}
	int result = Solve(Gift_num, Coupon_num, Need, Value, Best);
	cout << result << endl;
	return 0;
}