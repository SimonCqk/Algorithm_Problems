#include<iostream>
#include<algorithm>
//#include<string>
#define MAX_SIZE 100001
using namespace std;

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


long long Need[MAX_SIZE];
int Value[MAX_SIZE], Best[MAX_SIZE];
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
