//[编程题] 分饼干
//易老师购买了一盒饼干，盒子中一共有k块饼干，但是数字k有些数位变得模糊了，看不清楚数字具体是多少了。
//易老师需要你帮忙把这k块饼干平分给n个小朋友，易老师保证这盒饼干能平分给n个小朋友。
//现在你需要计算出k有多少种可能的数值
//输入描述 :
//输入包括两行：
//
//第一行为盒子上的数值k，模糊的数位用X表示，长度小于18(可能有多个模糊的数位)
//
//第二行为小朋友的人数n
//
//输出描述 :
//输出k可能的数值种数，保证至少为1
//
//输入例子 :
//9999999999999X
//3
//
//输出例子 :
//	4

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<ctype.h>
#include<sstream>
//#include<numeric>
//#include<cmath>
//#include<set>

using namespace std;

long long sync[10001], remain[10001];   //每一位数对应余数取值的可能性
int main() {
	string s;
	int n;
	cin >> s;
	cin >> n;
	sync[0] = 1;
	int s_size = s.size();
	for (int i = 0; i < s_size; ++i) {
		memset(remain, 0, sizeof(remain));
		for (int j = 0; j < n; j++) {       //这一位所能取的余数的可能性（0...n-1）
			for (int k = 0; k < 10; k++) {    //这一位能取的数，当然是0~9啦
				if (isdigit(s[i]) && s[i] - '0' != k) continue;
				//isdigit 判断是否为0~9的数字
				//若该位为k,则计算所有可能取值，否则只计算这一种取值
				remain[((j * 10) + k) % n] += sync[j];
				//计算当前值和前一位余数的取值组合产生的余数
			}
		}
		memcpy(sync, remain, sizeof(sync));  //与余数对应的取值同步
	}
	cout << sync[0] << endl;  //最后一位余数为0的的取值
}