/*
  输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
  打印出能拼接出的所有数字中最小的一个。
*/
#include<string>
#include<algorithm>
#include<vector>
#include<iostream>

std::string GetMinNumber(const std::vector<int>& arr) {
	if (arr.empty())
		return "";
	std::vector<std::string> num_strs;
	for (const int& i : arr)  // 先将所有数字转化为字符串表示
		num_strs.push_back(std::to_string(i));
	std::sort(num_strs.begin(), num_strs.end(), [](const std::string& lhs, const std::string& rhs) {
		// 两个字符串相加，位数一定相同，直接应用字符串的比较规则
		return (lhs + rhs) < (rhs + lhs);  
	});
	std::string ans;
	for (const std::string& str : num_strs)
		ans.append(str);
	return ans;
}

int main() {
	std::vector<int> sample{ 3,32,321,1 };
	std::cout << GetMinNumber(sample) << std::endl;
	return 0;
}
