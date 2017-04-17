/*
题目1 : Legendary Items
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
Little Hi is playing a video game. Each time he accomplishes a quest in the game, Little Hi has a chance to get a legendary item.

At the beginning the probability is P%. Each time Little Hi accomplishes a quest without getting a legendary item, the probability will go up Q%. Since the probability is getting higher he will get a legendary item eventually.

After getting a legendary item the probability will be reset to ⌊P/(2I)⌋% (⌊x⌋ represents the largest integer no more than x) where I is the number of legendary items he already has. The probability will also go up Q% each time Little Hi accomplishes a quest until he gets another legendary item.

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
官微解析：
可以发现第一件物品的获得和第二件物品的获得是独立事件。所以N件物品的总期望步数就是每一件的期望步数之和。
而每一件物品最多失败100次，所以可以直接算。

其他思路：
注意观察，这里前后两个物品，第一个物品取到的概率是P%，第二个就是[P/2]%，因为既然是第二个那一定有第一个。
这样其实reset操作与之前的物品就没有关系，这样看来，可以看作n个物品之间是相互独立的，每个都有一个初始概率[P/(2^i)]%。
而对于每个物品，因为概率不超过100%，所以最多加Q加到100%就结束了，最多有100次取不到。
这样就很简单了，模拟一下，算出每个物品的期望，再加起来，因为物品之间相互独立，所以最后结果就是取得n个物品的期望
*/

/*
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;

int main() {
//freopen("in.txt", "r", stdin);
int p, q, n;
scanf("%d%d%d", &p, &q, &n);
double ans = 0;
for (int i = 1; i <= n; i++) {
int sp = p;
double e = 0, pp = 1.0, cnt = 0;
while (true) {
e += (double)(++cnt) * pp * sp / 100;
if (sp == 100) break;
pp *= (double)(100 - sp) / 100;
sp += q;
if (sp >= 100) sp = 100;
}
p /= 2;
ans += e;
}
printf("%.2f\n", ans);
return 0;
}
*/