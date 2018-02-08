/*
  输入一个正数s，打印出所有和为s的正数序列（至少含有两个数）。
  例如输入15，因为1+2+3+4+5=4+5+6=7+8=15
*/
#include<iostream>

using namespace std;

void FindContinuousSeq(const int& sum) {
	if (sum < 3)
		return;
	int start = 1, end = 2;
	int mid = (sum + 1) / 2;
	int cur_sum = start + end;
	while (start < mid) {
		if (cur_sum == sum) {
			for (int i = start; i <= end; ++i)
				cout << i << ' ';
			cout << endl;
		}
		while (cur_sum > sum&&start < mid) {
			cur_sum -= start;
			start++;
			if (cur_sum == sum) {
				for (int i = start; i <= end; ++i)
					cout << i << ' ';
				cout << endl;
			}
		}
		++end;
		cur_sum += end;
	}
}

int main() {
	FindContinuousSeq(15);
	return 0;
}


