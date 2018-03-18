/*
  输入一个字符串，打印出该字符串中字符的所有排列。
  例如输入abc，则打印出abc,acb,bca,bac....
*/
#include<string>
#include<algorithm>
#include<iostream>

using std::string;

void Permutation(string str, const int& index) {
	str = std::move(str);
	if (index == str.size())
		std::cout << str << std::endl;
	else {
		for (size_t i = index; i < str.size(); ++i) {
			std::swap(str[index], str[i]);
			Permutation(str, index + 1);
			std::swap(str[index], str[i]); // roll back to origin string
		}
	}
}

void Permutation(string str) {
	if (str.empty())
		return;
	Permutation(str, 0);
}

// 非递归解法：(从最小字符串开始)
// 从后往前找，直到找到第一对递增的数AB,然后找A后面的比A大的数中的最小数，交换位置
// 交换后把原来A位置后面的字符串反转

void Permutation_NonRecur(string str) {
	str = std::move(str);
	std::sort(str.begin(), str.end()); // 确保是最小字符串
	std::cout << str << std::endl;
	int end = str.size() - 1;
	int pos = end; // 需要交换的点
	int next, min; // 交换点的下一点，交换点之后比它大的最小点
	while (pos > 0) {
		next = pos;
		--pos;
		if (str[pos] < str[next]) {
			// 找到pos之后比它大的所有点中的最小点
			// 从后往前找第一个比str[pos]大的数即是我们要找的数
			min = end;
			while (str[min] <= str[pos])
				--min;
			std::swap(str[pos], str[min]);
			std::reverse(str.begin() + next, str.end());
			std::cout << str << std::endl;
			pos = end;  //回到最后
		}
	}
}

int main() {
	string s = "cba";
	Permutation_NonRecur(s);
	return 0;
}