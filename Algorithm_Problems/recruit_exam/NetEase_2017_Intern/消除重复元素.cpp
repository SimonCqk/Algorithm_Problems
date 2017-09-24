//[编程题] 消除重复元素
//小易有一个长度为n序列，小易想移除掉里面的重复元素，但是小易想是对于每种元素保留最后出现的那个。小易遇到了困难, 希望你来帮助他。
//输入描述 :
//输入包括两行：
//第一行为序列长度n(1 ≤ n ≤ 50)
//第二行为n个数sequence[i](1 ≤ sequence[i] ≤ 1000)，以空格分隔
//
//
//输出描述 :
//输出消除重复元素之后的序列，以空格分隔，行末无空格
//
//输入例子 :
//9
//100 100 100 99 99 99 100 100 100
//
//输出例子 :
//	99 100

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