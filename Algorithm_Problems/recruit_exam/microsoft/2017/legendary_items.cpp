/*
题目1 : Legendary Items
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
Little Hi is playing a video game. Each time he accomplishes a quest in the game, Little Hi has a chance to get a legendary item.

At the beginning the probability is P%. Each time Little Hi accomplishes a quest without getting a legendary item, 
the probability will go up Q%. Since the probability is getting higher he will get a legendary item eventually.

After getting a legendary item the probability will be reset to ⌊P/(2^I)⌋% (⌊x⌋ represents the largest integer no more than x) 
where I is the number of legendary items he already has. The probability will also go up Q% each time Little Hi accomplishes 
a quest until he gets another legendary item.

Now Little Hi wants to know the expected number of quests he has to accomplish to get N legendary items.

Assume P = 50, Q = 75 and N = 2, as the below figure shows the expected number of quests is

2*50%*25% + 3*50%*75%*100% + 3*50%*100%*25% + 4*50%*100%*75%*100% = 3.25


输入
The first line contains three integers P, Q and N.

1 ≤ N ≤ 106, 0 ≤ P ≤ 100, 1 ≤ Q ≤ 100

输出
Output the expected number of quests rounded to 2 decimal places.

样例输入
50 75 2
样例输出
3.25
*/

/*
解析：
这里前后两个物品，第一个物品取到的概率是P%，第二个就是[P/2]%，因为既然是第二个那一定有第一个。
这样其实reset操作与之前的物品就没有关系，这样看来，可以看作n个物品之间是相互独立的，每个都有一个初始概率[P/(2^i)]%。
而对于每个物品，因为概率不超过100%，所以最多加Q加到100%就结束了，最多有100次取不到。
这样就很简单了，模拟一下，算出每个物品的期望，再加起来，因为物品之间相互独立，所以最后结果就是取得n个物品的期望
*/

#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int N, P, Q;
	cin >> P >> Q >> N;
	double ans = 0.0;
	for (int i = 1; i <= N; ++i) {
		int cur_p = P,cnt=0;
		double each_exp = 0, cannot_p = 1.0;
		while (true) {
			each_exp += (static_cast<double>((++cnt)*cur_p*cannot_p)) / 100;
			if (cur_p == 100)break;
			cannot_p *= (static_cast<double>(100 - cur_p) )/ 100;
			cur_p += Q;
			if (cur_p >= 100)cur_p = 100;
		}
		ans += each_exp;
		P >>= 1;
	}
	printf("%.2f", ans);
	cout << endl;
	return 0;
}