/*
 输入数字n,按顺序打印出从1到最大的n位十进制数。比如输入3，则打印出1,2,3...999.
*/

/*
 n的位数很大，很容易造成溢出，即使是long long 也不行。
 必须用字符串模拟数字
*/
#include<string>
#include<iostream>

using namespace std;

void PrintNumber(const string& num) {
	if (num.empty())
		return;
	int i = 0;
	while (num[i] == '0')
		++i;
	for (; i < num.size(); ++i)
		printf("%c", num[i]);
	cout << endl;
}

// 如果溢出，则返回false.
// 否则返回true;
bool Increment(string& num) {
	bool success = true;
	int size = num.size();
	int carry = 0;
	for (int i = size - 1; i >= 0; --i) {
		int sum = num[i] - '0' + carry;
		if (i == size - 1)
			++sum;
		if (sum >= 10) {
			if (i == 0)
				success = false;
			else {
				sum -= 10;
				carry = 1;
				num[i] = '0' + sum;
			}
		}
		else {
			num[i] = '0' + sum;
			break;
		}
	}
	return success;
}

void PrintOneToNDigits(int n) {
	if (n <= 0)
		return;
	string num(n, '0');
	while (Increment(num))
		PrintNumber(num);
}


int main() {
	PrintOneToNDigits(3);
	return 0;
}