
//[编程题] 集合
//小易最近在数学课上学习到了集合的概念, 集合有三个特征：1.确定性 2.互异性 3.无序性.
//小易的老师给了小易这样一个集合：
//S = { p / q | w ≤ p ≤ x, y ≤ q ≤ z }
//需要根据给定的w，x，y，z, 求出集合中一共有多少个元素。小易才学习了集合还解决不了这个复杂的问题, 需要你来帮助他。
//输入描述 :
//输入包括一行：
//一共4个整数分别是w(1 ≤ w ≤ x)，x(1 ≤ x ≤ 100)，y(1 ≤ y ≤ z)，z(1 ≤ z ≤ 100).以空格分隔
//
//
//输出描述 :
//输出集合中元素的个数
//
//输入例子 :
//1 10 1 1
//
//输出例子 :
//	10
//
#include<iostream>
//#include<map>
//#include<algorithm>
//#include<string>
//#include<vector>
//#include<cmath>
#include<set>
using namespace std;

set<pair<int, int>> SET;
int w, x, y, z;
int gcd(int x, int y) //用辗转相除法，求两数的最大公约数
{
	int r;
	while (y > 0)
	{
		r = x%y;
		x = y;
		y = r;
	}
	return x;
}

int main() {
	cin >> w >> x >> y >> z;
	for (int i = w; i <= x; ++i)
		for (int j = y; j <= z; ++j) {
			int p = i, q = j;
			int div = gcd(i, j);
			SET.insert(make_pair(i / div, j / div));
		}
	int set_size = SET.size();
	cout << set_size << endl;
	return 0;
}