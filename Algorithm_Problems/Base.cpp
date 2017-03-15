/*
int solve(int i,int m){
	if(m==0)return 1;
	if(i>=n)return 0;
	int result=solve(i+1,m)||solve(i+1,m-A[i]);
	return result;
	}
	//	
*/


#include<iostream>
#include<algorithm>
//#include<string>
#define MAX_Coupon 100001
#define MAX_Gift 500
using namespace std;

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


long long Need[MAX_Coupon];
int Value[MAX_Coupon], Best[MAX_Gift][MAX_Coupon];
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