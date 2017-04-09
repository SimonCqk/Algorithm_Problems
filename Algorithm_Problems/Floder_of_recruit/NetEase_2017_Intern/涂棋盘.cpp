//
//[编程题] 涂棋盘
//小易有一块n*n的棋盘，棋盘的每一个格子都为黑色或者白色，小易现在要用他喜欢的红色去涂画棋盘。
//小易会找出棋盘中某一列中拥有相同颜色的最大的区域去涂画，帮助小易算算他会涂画多少个棋格。
//输入描述 :
//输入数据包括n + 1行：
//
//第一行为一个整数n(1 ≤ n ≤ 50), 即棋盘的大小
//
//接下来的n行每行一个字符串表示第i行棋盘的颜色，'W'表示白色，'B'表示黑色
//
//
//输出描述 :
//输出小易会涂画的区域大小
//
//输入例子 :
//3
//BWW
//BBB
//BWB
//
//输出例子 :
//3


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

