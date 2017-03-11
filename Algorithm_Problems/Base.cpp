/*
//穷举搜索问题
长度n的数列A和整数m，判断A中任意几个元素相加是否能得到m,A中每个元素只能用一次。
利用一个递归函数判断：

int solve(int i,int m){
	if(m==0)return 1;
	if(i>=n)return 0;
	int result=solve(i+1,m)||solve(i+1,m-A[i]);
	return result;
	}
	//	不适用于n较大问题，复杂度为O（2^n），或用动态规划优化
*/


#include<iostream>
#include<algorithm>

using namespace std;


int main() {
	
	return 0;
}