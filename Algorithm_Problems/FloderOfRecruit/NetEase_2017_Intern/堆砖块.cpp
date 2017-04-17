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

//  ***********打星号*********
//  这题折磨我很久...毕竟DP刚入门，然后带着nowcoder上的示例代码求教了我们学校ACM的人
//  才懂了解题思路...  (╯︵╰)

//  从没有砖块开始分析。考虑每块砖块放入的决策,放入左边,放入右边和不使用这块砖块三种情况
//  dp[p][gap]表示只用前p块砖堆成高度相差gap的两座塔的较高的一座的塔的高度
//  所以gap + height[i]当作往左边塔放入砖块
//  gap - height当作右边塔放入砖块 右边塔放入时高度也会增加
//  如果不放入就用前置状态,三个求最大值
//  因为只需要知道[P-1][]就可以求出[P][]所以把p循环置0置1（滚动数组）节省空间



#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
const int MAX_NUM = 500010;
int n;
int DP[2][MAX_NUM];

int solve(vector<int>& len) {
	memset(DP, 0, sizeof(DP));  //initialize the DP array
	int p = 0;
	auto len_size = len.size();
	for (int i = 0; i < len_size; ++i) {
		DP[p][len[i]] = max(DP[1 - p][len[i]], len[i]);
		for (int gap = 0; gap < MAX_NUM; ++gap) {
			if (DP[1 - p][gap]) {  //if the tower exsists
				if (DP[p][gap] < DP[1 - p][gap])DP[p][gap] = DP[1 - p][gap];
				DP[p][gap + len[i]] = max(DP[p][gap + len[i]], max(DP[1 - p][gap + len[i]], DP[1 - p][gap] + len[i]));
				DP[p][abs(gap - len[i])] = max(DP[p][abs(gap - len[i])], max(DP[1 - p][abs(gap - len[i])], max(DP[1 - p][gap] - gap + len[i], DP[1 - p][gap])));
			}
		}
		p = 1 - p;
	}
	int result = (DP[1 - p][0]) ? DP[1 - p][0] : -1;
	return result;
}

int main() {
	vector<int> length;
	cin >> n;
	int item;
	for (int i = 0; i < n; ++i) {
		cin >> item; length.push_back(item);
	}
	int result = solve(length);
	cout << result << endl;
	return 0;
}

/*
//简书上看到了另一个版本的，解法大同小异，这里也放上来对比
//但是感觉这一种解法的可读性更好


#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int dp[2][2*N]; //第一维滚动状态 第二维两个塔的差值
int height[55];
int main()
{
int n;
cin >> n;
for (int i = 1; i <= n; i++)
{
scanf("%d", &height[i]);
}
memset(dp, 0, sizeof(dp));
int p = 0;

for (int j = 0; j < 2*N; j++) dp[1-p][j] = INT_MIN; //保证第一次取不到
dp[1-p][N] = 0;//入口
for (int i = 1; i <= n; i++)
{
for (int j = height[i]; j < 2*N; j++)
{
dp[p][j] = max(dp[1-p][j-height[i]]+height[i], dp[1-p][j]); //放到右边减小差距并增加塔高 以及不放入砖块
}
for (int j = 0; j+height[i] < 2*N; j++)
{
dp[p][j] = max(dp[p][j], dp[1-p][j+height[i]]); //放到左边增加差距
}
p = 1 - p;
}
if (dp[1-p][N]) cout << dp[1-p][N] << endl;
else cout <<-1;
return 0;
}


*/