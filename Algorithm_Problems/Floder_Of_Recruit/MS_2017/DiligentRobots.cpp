/*

#1498 : Diligent Robots
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
There are N jobs to be finished. It takes a robot 1 hour to finish one job.

At the beginning you have only one robot. Luckily a robot may build more robots identical to itself.
It takes a robot Q hours to build another robot.

So what is the minimum number of hours to finish N jobs?

Note two or more robots working on the same job or building the same robot won't accelerate the progress.

输入
The first line contains 2 integers, N and Q.

For 70% of the data, 1 <= N <= 1000000

For 100% of the data, 1 <= N <= 1000000000000, 1 <= Q <= 1000

输出
The minimum number of hours.

样例输入
10 1
样例输出
5
*/

#include<iostream>
#include<algorithm>

using namespace std;

//total time = n/(2^times)+times*q ;

int main() {
	long long n; int q;
	cin >> n >> q;
	long long rbt_num = 1;
	long long ans = n;
	long long times = 0;
	long long fns_things_time;
	while (true) {
		fns_things_time = n / rbt_num;
		if (n%rbt_num)++fns_things_time;   //不能被整除，则时间 + 1
		ans = min(ans, fns_things_time + times*q);
		rbt_num <<= 1;   //rbt_num *= 2;
		times++;
		if (rbt_num >= n)break;
	}
	cout << ans << endl;
	return 0;
}