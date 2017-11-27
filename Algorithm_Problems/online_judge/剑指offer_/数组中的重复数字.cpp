/*
长度为n的数组，所有数字范围在0~n-1内。某些数字重复，找出任意一个重复的数字。
解法：时间复杂度O(n)，空间复杂度O(1).
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;;

bool Duplicate(vector<int>& arr, int& duplication) {
	if (arr.empty())
		return false;
	// 判断范围是否合法
	int size = arr.size();
	for (auto& num : arr)
		if (num<0 || num>size - 1)
			return false;
	for (int i = 0; i < size; ++i) {
		while (arr[i] != i) {
			if (arr[i] == arr[arr[i]]) {
				duplication = arr[i];
				return true;
			}
			std::swap(arr[i], arr[arr[i]]);
		}
	}
	return false;
}

int main() {
	vector<int> test{ 3,2,1,0,2,5,3 };
	int ans;
	if (Duplicate(test, ans))
		cout << "Find target -> " << ans << endl;
	else
		cout << "No such number." << endl;
	return 0;
}