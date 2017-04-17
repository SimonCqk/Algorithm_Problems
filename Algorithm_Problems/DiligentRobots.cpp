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
假设生了k次机器人，那么时间就是n/2^k+k*q
n，q已知，那么枚举k就行~~

#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
typedef long long LL;
int main()
{
LL n,q;
cin>>n>>q;
if(n<=2*q)
{
cout<<n<<endl;
}
else
{
LL ans=1e12;
for(LL k=0; ; k++)
{
LL hour = 1LL<<k;
if(hour>n)
{
break;
}
if(n%hour==0)
{
ans=min(ans,(n/hour)+k*q);
}
else
{
ans=min(ans,(n/hour)+1+k*q);
}
}
cout<<ans<<endl;
}

}

*/

/*
不断分裂，然后计算时间，取个最小值。
#include<bits/stdc++.h>
using namespace std;

long long n;
int q;

int main()
{
scanf("%lld%d",&n,&q);

long long now=1;
long long ans=n;
long long ci=0;

while(1)
{
long long nd = n/now;
if(n%now!=0) nd++;
ans=min(ans,nd+q*ci);
now=now*2;
ci++;
if(now>=n) break;
}

printf("%lld\n",ans);

return 0;
}
*/