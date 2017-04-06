/*
[编程题] 堆砖块
小易有n块砖块，每一块砖块有一个高度。小易希望利用这些砖块堆砌两座相同高度的塔。
为了让问题简单，砖块堆砌就是简单的高度相加，某一块砖只能使用在一座塔中一次。
小易现在让能够堆砌出来的两座塔的高度尽量高，小易能否完成呢。
输入描述:
输入包括两行：
第一行为整数n(1 ≤ n ≤ 50)，即一共有n块砖块
第二行为n个整数，表示每一块砖块的高度height[i] (1 ≤ height[i] ≤ 500000)


输出描述:
如果小易能堆砌出两座高度相同的塔，输出最高能拼凑的高度，如果不能则输出-1.
保证答案不大于500000。

输入例子:
3
2 3 5

输出例子:
5
*/


//#include<map>
#include<iostream>
#include<algorithm>
//#include<string>
#include<vector>
//#include<ctype.h>
//#include<sstream>
//#include<numeric>
//#include<cmath>
//#include<set>

using namespace std;
//const int MAX_SIZE = 51;
const int MAX_NUM = 500001;
int n;
vector<int> length;


int main() {
	cin >> n;
	int item;
	for (int i = 0; i < n; ++i) {
		cin >> item; length.push_back(item);
	}
	
	return 0;
}



/*

#include <bits/stdc++.h>

using namespace std;

const int maxn = 500010;
int n;
vector<int> a;
int dp[2][maxn];
int solve(vector<int> v) {
int res = 0;
memset(dp, 0, sizeof(dp));
int p = 0;
for(int i = 0; i < v.size(); i++) {
dp[p][v[i]] = max(dp[1-p][v[i]] , v[i]);
for(int ix = 0; ix < maxn; ix++) {
if(dp[1 - p][ix]) {
if(dp[p][ix] < dp[1 - p][ix]) dp[p][ix] = dp[1-p][ix];
dp[p][ix + v[i]] = max(dp[p][ix + v[i]], max(dp[1 - p][ix + v[i]], dp[1 - p][ix] + v[i]));
dp[p][abs(ix - v[i])] = max(dp[p][abs(ix - v[i])], max(dp[1 - p][abs(ix - v[i])], max(dp[1-p][ix] - ix + v[i], dp[1 - p][ix])));
}
}
p = 1 - p;
}
if(dp[1 - p][0]) res = dp[1 - p][0];
else res = -1;
return res;
}
int main() {
cin >> n;
for(int i = 0; i < n; i++) {
int x; cin >> x;
a.push_back(x);
}
cout << solve(a) << endl;
return 0;
}
*/