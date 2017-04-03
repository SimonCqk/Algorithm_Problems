/*
[编程题] 消除重复元素
小易有一个长度为n序列，小易想移除掉里面的重复元素，但是小易想是对于每种元素保留最后出现的那个。小易遇到了困难,希望你来帮助他。
输入描述:
输入包括两行：
第一行为序列长度n(1 ≤ n ≤ 50)
第二行为n个数sequence[i](1 ≤ sequence[i] ≤ 1000)，以空格分隔


输出描述:
输出消除重复元素之后的序列，以空格分隔，行末无空格

输入例子:
9
100 100 100 99 99 99 100 100 100

输出例子:
99 100
#include<iostream>
#include<map>
//#include<algorithm>
//#include<string>
#include<vector>
#define MAXSIZE 51
using namespace std;

int a[MAXSIZE];
map<int, int>COUNT;	//标记元素出现的次数
vector<int>FINAL;	//存储最终的不重复序列

int main() {
int n; cin >> n;
for (int i = 0; i < n; ++i)cin >> a[i];
for (int i = 0; i < n; ++i)++COUNT[a[i]]; //开始计数
for (int i = 0; i < n; ++i) {			  //将最后一个不重复元素push_back
--COUNT[a[i]];
if (!COUNT[a[i]]) {
FINAL.push_back(a[i]);
}
}
size_t sz = FINAL.size();
for (int i = 0; i < sz; ++i) {          //输出容器中的不重复元素，注意格式
if (i == sz - 1)cout << FINAL[i];
else cout << FINAL[i] << ' ';
}
cout << endl;
return 0;
}


[编程题] 赶去公司
终于到周末啦！小易走在市区的街道上准备找朋友聚会，突然服务器发来警报,小易需要立即回公司修复这个紧急bug。假设市区是一个无限大的区域，每条街道假设坐标是(X，Y)，小易当前在(0，0)街道，办公室在(gx,gy)街道上。小易周围有多个出租车打车点，小易赶去办公室有两种选择，一种就是走路去公司，另外一种就是走到一个出租车打车点，然后从打车点的位置坐出租车去公司。每次移动到相邻的街道(横向或者纵向)走路将会花费walkTime时间，打车将花费taxiTime时间。小易需要尽快赶到公司去，现在小易想知道他最快需要花费多少时间去公司。
输入描述:
输入数据包括五行:

第一行为周围出租车打车点的个数n(1 ≤ n ≤ 50)

第二行为每个出租车打车点的横坐标tX[i] (-10000 ≤ tX[i] ≤ 10000)

第三行为每个出租车打车点的纵坐标tY[i] (-10000 ≤ tY[i] ≤ 10000)

第四行为办公室坐标gx,gy(-10000 ≤ gx,gy ≤ 10000),以空格分隔

第五行为走路时间walkTime(1 ≤ walkTime ≤ 1000)和taxiTime(1 ≤ taxiTime ≤ 1000),以空格分隔


输出描述:
输出一个整数表示，小易最快能赶到办公室的时间

输入例子:
2
-2 -2
0 -2
-4 -2
15 3

输出例子:
42
#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
//#include<string>
#include<vector>
#define MAXSIZE 51
using namespace std;

#define LOOP(n) for(int i=0;i<n;++i)

struct TaxiLoc
{
int Tx;
int Ty;
};
int n, Gx, Gy;
int walktime, taxitime;

int main() {
TaxiLoc TL[MAXSIZE];
cin >> n;
LOOP(n)cin >> TL[i].Tx;
LOOP(n)cin >> TL[i].Ty;
cin >> Gx >> Gy;
cin >> walktime >> taxitime;
int answer = walktime*(abs(Gx) + abs(Gy));
LOOP(n) {
int pivot = taxitime*(abs(Gx-TL[i].Tx)+abs(Gy-TL[i].Ty)) + walktime*(abs(TL[i].Tx) + abs(TL[i].Ty));
answer = min(pivot, answer);
}
cout << answer << endl;
return 0;
}

[编程题] 集合
小易最近在数学课上学习到了集合的概念,集合有三个特征：1.确定性 2.互异性 3.无序性.
小易的老师给了小易这样一个集合：
S = { p/q | w ≤ p ≤ x, y ≤ q ≤ z }
需要根据给定的w，x，y，z,求出集合中一共有多少个元素。小易才学习了集合还解决不了这个复杂的问题,需要你来帮助他。
输入描述:
输入包括一行：
一共4个整数分别是w(1 ≤ w ≤ x)，x(1 ≤ x ≤ 100)，y(1 ≤ y ≤ z)，z(1 ≤ z ≤ 100).以空格分隔


输出描述:
输出集合中元素的个数

输入例子:
1 10 1 1

输出例子:
10

#include<iostream>
//#include<map>
//#include<algorithm>
//#include<string>
//#include<vector>
//#include<cmath>
#include<set>
using namespace std;

set<pair<int,int>> SET;
int w, x, y, z;
int gcd(int x, int y) //用辗转相除法，求两数的最大公约数
{
int r;
while (y>0)
{
r = x%y;
x = y;
y = r;
}
return x;
}

int main() {
cin >> w >> x >> y >> z;
for(int i=w;i<=x;++i)
for (int j = y; j <= z; ++j) {
int p = i, q = j;
int div = gcd(i, j);
SET.insert(make_pair(i/div, j/div));
}
int set_size = SET.size();
cout << set_size<<endl;
return 0;
}

[编程题] 奇怪的表达式求值
常规的表达式求值，我们都会根据计算的优先级来计算。比如*,/的优先级就高于 + -。但是小易所生活的世界的表达式规则很简单，从左往右依次计算即可，而且小易所在的世界没有除法，意味着表达式中没有 / ，只有(+, -和 *)。现在给出一个表达式，需要你帮忙计算出小易所在的世界这个表达式的值为多少
输入描述 :
输入为一行字符串，即一个表达式。其中运算符只有 - , +, *。参与计算的数字只有0~9.
保证表达式都是合法的，排列规则如样例所示。


输出描述 :
输出一个数，即表达式的值

输入例子 :
3 + 5 * 7

输出例子 :
	56

	#include<iostream>
	//#include<map>
	#include<algorithm>
	#include<string>
	//#include<vector>
	//#include<cmath>
	//#include<set>

	using namespace std;

	int main() {

	string expression;
	int result;
	cin >> expression;
	auto it = expression.begin();
	result = *(it++)-'0';
	while (it!=expression.end()) {
	if (*it == '+') {
	result = result + (*(++it)-'0');
	++it; continue;
	}
	else if (*it == '*') {
	result = result *(*(++it) - '0');
	++it; continue;
	}
	else if (*it == '-') {
	result = result - (*(++it) - '0');
	++it; continue;
	}
	}
	cout << result<<endl;
	return 0;
	}

	[编程题] 调整队形
	在幼儿园有n个小朋友排列为一个队伍，从左到右一个挨着一个编号为(0~n-1)。其中有一些是男生，有一些是女生，男生用'B'表示，女生用'G'表示。小朋友们都很顽皮，当一个男生挨着的是女生的时候就会发生矛盾。作为幼儿园的老师，你需要让男生挨着女生或者女生挨着男生的情况最少。你只能在原队形上进行调整，每次调整只能让相邻的两个小朋友交换位置，现在需要尽快完成队伍调整，你需要计算出最少需要调整多少次可以让上述情况最少。例如：
	GGBBG -> GGBGB -> GGGBB
	这样就使之前的两处男女相邻变为一处相邻，需要调整队形2次
	输入描述:
	输入数据包括一个长度为n且只包含G和B的字符串.n不超过50.


	输出描述:
	输出一个整数，表示最少需要的调整队伍的次数

	输入例子:
	GGBBG

	输出例子:
	2

	#include<iostream>
	//#include<map>
	#include<algorithm>
	#include<string>
	#include<vector>
	//#include<numeric>
	//#include<cmath>
	//#include<set>

	using namespace std;

	string QUEUE;
	int result,Num_G=0,Num_B=0;
	vector<int>Result_G, Result_B;
	int main() {
	cin >> QUEUE;
	size_t len = QUEUE.size();
	int i = 0;
	int sum_G=0, sum_B=0;
	//auto it = QUEUE.begin(), END = QUEUE.end();
	while (i<len) {
	if (QUEUE[i] == 'G') {
	++Num_G; Result_G.push_back(i);
	}
	if (QUEUE[i] == 'B') {
	++Num_B; Result_B.push_back(i);
	}
	++i;
	}
	for (i = 0; i < Num_G; ++i)sum_G += (Result_G[i] - i);
	for (i = 0; i < Num_B; ++i)sum_B += (Result_B[i] - i);
	result = min(sum_B, sum_G);
	cout << result << endl;
	return 0;
	}

	[编程题] 魔力手环
	小易拥有一个拥有魔力的手环上面有n个数字(构成一个环),当这个魔力手环每次使用魔力的时候就会发生一种奇特的变化：每个数字会变成自己跟后面一个数字的和(最后一个数字的后面一个数字是第一个),一旦某个位置的数字大于等于100就马上对100取模(比如某个位置变为103,就会自动变为3).现在给出这个魔力手环的构成，请你计算出使用k次魔力之后魔力手环的状态。
	输入描述:
	输入数据包括两行：
	第一行为两个整数n(2 ≤ n ≤ 50)和k(1 ≤ k ≤ 2000000000),以空格分隔
	第二行为魔力手环初始的n个数，以空格分隔。范围都在0至99.


	输出描述:
	输出魔力手环使用k次之后的状态，以空格分隔，行末无空格。

	输入例子:
	3 2
	1 2 3

	输出例子:
	8 9 7

	#include<iostream>
	//#include<map>
	#include<algorithm>
	//#include<string>
	#include<vector>
	//#include<numeric>
	//#include<cmath>
	//#include<set>
	const int MAX_SIZE = 101;
	using namespace std;
	typedef vector<vector<int>> Matrix;

	const int MOD = 100;
	vector<int> Magic;
	int n; long long int k;

	Matrix Matrix_init(MAX_SIZE,vector<int>(MAX_SIZE,0)) ;
	void Make_init(Matrix& Matrix_init) {
	for (int i = 0; i < n; ++i) {
	Matrix_init[i][i] =Matrix_init[i][(i + 1) % n] = 1;
	}
	}
	/*
	k的数量级太大，直接甩你一个TLE
	void Solve(vector<int>& Magic) {
	int flag = Magic[0];
	for (long long int i = 0; i < k; ++i) {
	for (int j = 0; j < n; ++j) {
	if (j == n - 1)Magic[j] += flag;
	else Magic[j] += Magic[j + 1];
	if (Magic[j] > 100)Magic[j] %= 100;
	}
	flag = Magic[0];
	}
	}
	*/
	//
	//最终的结果相当于 魔力环构成的一维向量[0...n-1]与
	//	[1 1 0 0 ...]
	//	[0 1 1 0 ...]
	//	[0 0 1 1 ...]
	//	[...........]
	//	[1 0 0.....1]
	//	这样的矩阵相乘
	//  为了在规定时间内运行，利用矩阵的快速幂优化  
	//快速幂blog参考：http ://blog.csdn.net/hikean/article/details/9749391
/*
Matrix Matrix_mul(Matrix a, Matrix b) {
	Matrix temp(n, vector<int>(n, 0));
	for (int i = 0; i<n; ++i)
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				temp[i][j] += a[i][k] * b[k][j];
				temp[i][j] %= MOD;
			}

		}
	return temp;
}

Matrix Quick_pow(Matrix a, long long int k) {
	long long int N = k;
	Matrix ANS(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
		ANS[i][i] = 1;
	while (N) {
		if (N & 1) {  //即n%2
			ANS = Matrix_mul(ANS, a);
		}
		N = N >> 1;   //即n=n/2
		a = Matrix_mul(a, a);
	}
	return ANS;
}

vector<int> Magic_mul(vector<int> Magic, Matrix BASE) {
	vector<int> temp;
	int flag;
	for (int i = 0; i < n; ++i) {
		flag = 0;
		for (int k = 0; k < n; ++k) {
			flag = (flag + Magic[k] * BASE[i][k]) % MOD;
		}
		temp.push_back(flag);
	}
	return temp;
}

int main() {
	cin >> n;
	cin >> k;
	int item;
	for (int i = 0; i < n; ++i) {
		cin >> item;
		Magic.push_back(item);
	}
	Matrix BASE(n, vector<int>(n, 0));
	Make_init(Matrix_init);
	BASE = Quick_pow(Matrix_init, k);
	Magic = Magic_mul(Magic, BASE);
	for (int i = 0; i < n; ++i) {
		(i == n - 1) ? cout << Magic[i] : cout << Magic[i] << ' ';
	}
	cout << endl;
	return 0;
}

[编程题] 双核处理
一种双核CPU的两个核能够同时的处理任务，现在有n个已知数据量的任务需要交给CPU处理，假设已知CPU的每个核1秒可以处理1kb，
每个核同时只能处理一项任务。n个任务可以按照任意顺序放入CPU进行处理，
现在需要设计一个方案让CPU处理完这批任务所需的时间最少，求这个最小的时间。
输入描述 :
输入包括两行：
第一行为整数n(1 ≤ n ≤ 50)
第二行为n个整数length[i](1024 ≤ length[i] ≤ 4194304)，表示每个任务的长度为length[i]kb，每个数均为1024的倍数。


输出描述 :
输出一个整数，表示最少需要处理的时间

输入例子 :
5
3072 3072 7168 3072 1024

输出例子 :
9216


#include<iostream>
//#include<map>
#include<algorithm>
//#include<string>
#include<vector>
#include<numeric>
//#include<cmath>
//#include<set>
using namespace std;
const int MAX_SIZE = 51;
vector<int> Length_n;

int n;

//使得max(cpu_one_time,cpu_two_time)最小
//   =====> 01 bag 模型：
//体积为sum/2，共有n个物体，代价为t[i]，价值也是t[i]，尽量多的装
//0-1 bag 思路补充：
//有N件物品和一个容量为V的背包。第i件物品的费用是c[i],价值是w[i],求解将哪些物品放入背包可使价值总和最大
//特点： 每一件物品仅有一件，能够选择放或者不放。 
//定义状态：F[i][v]:表示前i件物品恰好放入一个容量为v的背包能够获得的最大的价值 
//转移方程：F[i][v]=max(F[i-1][v],F[i-1][v-c[i]]+w[i]]); 
//优化空间复杂度： 以上求法时间和空间复杂度均为O(V*N),时间复杂度不能在优化了，然而空间复杂度能够进一步优化
//我们这样考虑：仅仅用一个数组F[0..V],保证第i次循环结束结束后F[v]表示的是就是定义的状态F[i][v]


int solve(vector<int>& Len, int sum) {
	int halfsum = sum >> 1;
	vector<int> DP(halfsum + 1, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = halfsum; j >= Len[i]; --j)
			DP[j] = max(DP[j], DP[j - Len[i]] + Len[i]);
	}
	return DP[halfsum];
}

int main() {
	cin >> n; int item;
	for (int i = 0; i < n; ++i) {
		cin >> item;
		Length_n.push_back(item / 1024);
	}
	//sort(Length_n.begin(), Length_n.end());
	int SUM = accumulate(Length_n.begin(), Length_n.end(), 0);
	int result = max(solve(Length_n, SUM), SUM - solve(Length_n, SUM));
	cout << result * 1024 << endl;
	return 0;
}


[编程题] 涂棋盘
小易有一块n*n的棋盘，棋盘的每一个格子都为黑色或者白色，小易现在要用他喜欢的红色去涂画棋盘。
小易会找出棋盘中某一列中拥有相同颜色的最大的区域去涂画，帮助小易算算他会涂画多少个棋格。
输入描述:
输入数据包括n+1行：

第一行为一个整数n(1 ≤ n ≤ 50),即棋盘的大小

接下来的n行每行一个字符串表示第i行棋盘的颜色，'W'表示白色，'B'表示黑色


输出描述:
输出小易会涂画的区域大小

输入例子:
3
BWW
BBB
BWB

输出例子:
3


#include<iostream>
//#include<map>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
//#include<cmath>
//#include<set>
using namespace std;
const int MAX_SIZE = 51;

vector<string> ChessBoard(MAX_SIZE);
int n, paint_num;
int solve(vector<string>& CB) {
	vector<int> count_w(MAX_SIZE, 1), count_b(MAX_SIZE, 1);
	int flag_w, flag_b;
	for (int i = 0; i < n; ++i) {	//i是列
		flag_b = flag_w = 0;
		for (int j = 0; j < n; ++j) {    //j是行
			if (CB[j][i] == 'W') {
				++flag_w; flag_b = 0;
				if (flag_w > count_w[j])count_w[j] = flag_w;
			}
			else if (CB[j][i] == 'B') {
				++flag_b; flag_w = 0;
				if (flag_b > count_b[j])count_b[j] = flag_b;
			}
		}
	}
	sort(count_w.rbegin(), count_w.rend());
	sort(count_b.rbegin(), count_b.rend());
	return max(count_w[0], count_b[0]);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> ChessBoard[i];
	int result = solve(ChessBoard);
	cout << result << endl;
	return 0;
}


[编程题] 小易记单词
小易参与了一个记单词的小游戏。游戏开始系统提供了m个不同的单词，小易记忆一段时间之后需要在纸上写出他记住的单词。
小易一共写出了n个他能记住的单词，如果小易写出的单词是在系统提供的，将获得这个单词长度的平方的分数。
注意小易写出的单词可能重复，但是对于每个正确的单词只能计分一次。
输入描述:
输入数据包括三行：

第一行为两个整数n(1 ≤ n ≤ 50)和m(1 ≤ m ≤ 50)。以空格分隔

第二行为n个字符串，表示小易能记住的单词，以空格分隔，每个单词的长度小于等于50。

第三行为m个字符串，系统提供的单词，以空格分隔，每个单词的长度小于等于50。


输出描述:
输出一个整数表示小易能获得的分数

输入例子:
3 4
apple orange strawberry
strawberry orange grapefruit watermelon

输出例子:
136


//#include<map>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
//#include<numeric>
//#include<cmath>
#include<set>
using namespace std;
//const int MAX_SIZE = 51;
int n, m;
vector<string> Sys;
set<string> Rem;

int solve(set<string>& rem, vector<string>& sys) {
	int result = 0;
	auto flag = sys.end();
	auto sbegin = rem.begin(), send = rem.end();
	for (; sbegin != send; ++sbegin) {
		if (find(sys.begin(), sys.end(), *sbegin) != flag)result += ((*sbegin).size()*(*sbegin).size());
	}
	return result;
}
int main() {
	cin >> n >> m;
	int result;
	string item;
	for (int i = 0; i < n; ++i) {
		cin >> item;
		Rem.insert(item);
	}
	for (int i = 0; i < m; ++i) {
		cin >> item;
		Sys.push_back(item);
	}
	result = solve(Rem, Sys);
	cout << result << endl;
	return 0;
}


[编程题] 分饼干
易老师购买了一盒饼干，盒子中一共有k块饼干，但是数字k有些数位变得模糊了，看不清楚数字具体是多少了。
易老师需要你帮忙把这k块饼干平分给n个小朋友，易老师保证这盒饼干能平分给n个小朋友。
现在你需要计算出k有多少种可能的数值
输入描述:
输入包括两行：

第一行为盒子上的数值k，模糊的数位用X表示，长度小于18(可能有多个模糊的数位)

第二行为小朋友的人数n

输出描述:
输出k可能的数值种数，保证至少为1

输入例子:
9999999999999X
3

输出例子:
4

//#include<map>
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
		for (int j = 0; j < n; j++) {       //这一位所能取的余数的可能性
			for (int k = 0; k < 10; k++) {    //这一位能取的数，当然是0~9啦
				if (isdigit(s[i]) && s[i] - '0' != k) continue;
				//isdigit->判断是否为0~9的数字
				//若该位为k,则计算所有可能取值，否则只计算这一种取值
				remain[((j * 10) + k) % n] += sync[j];
				//计算当前值和前一位余数的取值组合产生的余数
			}
		}
		memcpy(sync, remain, sizeof(sync));  //与余数对应的取值同步
	}
	cout << sync[0] << endl;  //最后一位余数为0的的取值
}


*/