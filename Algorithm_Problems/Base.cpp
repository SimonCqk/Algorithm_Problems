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

/*
//	快速排序/分治法
int Partiton(int A[], int p, int r) {
int pivot = A[r];
int i = p - 1;
for (int j = p; j < r ; ++j) {
if (A[j] <= pivot) { i += 1; std::swap(A[i], A[j]); }
}
std::swap(A[i + 1], A[r]);
return i + 1;
}

void Quick_Sort(int A[], int p, int r) {
int q;
if (p < r) {
q = Partiton(A, p, r);
Quick_Sort(A, p, q - 1);
Quick_Sort(A, q+1,r);
}
}

*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>

using namespace std;


int main() {
	
	return 0;
}