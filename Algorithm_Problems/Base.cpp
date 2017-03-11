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
const int MAX = 1000;
const int VMAX = 10000;
#define loop(n) for (int i = 0; i < n; ++i) 
int n, min_elem;//min_elem是所有w(i)中的最小元素，n为数量
int A[MAX], B[MAX], T[MAX + 1];

int Solve() {
	int ans=0;
	bool V[MAX];
	loop(n) { B[i] = A[i]; V[i] = false; }
	sort(B, B + n);		      //最终形态即sorted B[]
	loop(n)T[B[i]] = i;       //T[]记录B[i]对应的下标i
	loop(n) {
		if (V[i])continue;
		int cur = i;
		int s = 0, m = VMAX, an = 0;
		while (true) {
			V[cur] = true;    //到达，标记此V[i]
			++an;             //an=独立圆中的元素个数
			int v = A[cur];   
			m = min(m, v);    //m=独立圆中的最小元素
			s += v;		      //s=独立圆元素之和
			cur = T[v];        //cur=T[A[i]] 即A[]被排序后(B[])，A[i]对应的下标
			if (V[cur])break;  //回到自己，遍历形成一个独立圆，break while_loop；
		}
		ans += min(s + (an - 2)*m, m + s + (an + 1)*min_elem);   //每次比较（借整体最小元素）和（不借元素），取最小值
	}
	return ans;
}

int main() {
	cin >> n;
	min_elem = VMAX;
	loop(n) { cin >> A[i]; min_elem = min(min_elem, A[i]); }
	int answer = Solve();
	cout << answer << endl;
	return 0;
}