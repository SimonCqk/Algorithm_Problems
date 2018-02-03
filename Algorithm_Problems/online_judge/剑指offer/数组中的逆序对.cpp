/*
  在数组中的两个数字，如果前一个大于后一个，则这两个数字构成一个逆序对。
  输入一个数组，求这个数组中的逆序对个数。
  例如{7,5,6,4},一共存在5个逆序对。
*/
#include<vector>

using namespace std;


/*
  递归：先把数组划分成子数组，相邻两两统计，统计出子数组内部的逆序数的数目，
  利用归并排序（都是从最后一个数字开始）的思想，1.左子数组指针指向的数大于右边，
  构成逆序对，数目为右子数组中剩余数字的个数；
*/
int InversePairsCore(vector<int>& data, vector<int>& copy, int start, int end) {
	if (start == end) {
		copy[start] = data[start];
		return 0;
	}
	int mid = (end - start) / 2;
	int left = InversePairsCore(copy, data, start, start + mid);     // 每一次递归都是原数组和辅助数组新旧交替更新，所以
	int right = InversePairsCore(copy, data, start + mid + 1, end);  // copy和data是每次都是交替位置！(更新之后，新局部
	int i = start + mid, j = end;									 // 排序后的copy等同于下一次的原数组)
	int count = 0;
	int index = end;  // 指示应当移入copy中的下标
	while (i >= start && j >= start + mid + 1) {
		if (data[i] > data[j]) {
			count += j - start - mid; // j-(start+mid)
			copy[index--] = data[i--];
		}
		else
			copy[index--] = data[j--];
	}
	while (i >= start)
		copy[index--] = data[i--];
	while (j >= start + mid + 1)
		copy[index--] = data[j--];
	return left + right + count;
}


int InversePairs(vector<int> data) {  // 值传递 + move，可以不改变原来的数组
	data = std::move(data);
	if (data.empty())
		return 0;
	vector<int> copy(data.cbegin(), data.cend());
	return InversePairsCore(data, copy, 0, data.size() - 1);
}

int main() {
	vector<int> data{ 7,5,6,4 };
	std::printf("%d\n", InversePairs(data));
	return 0;
}