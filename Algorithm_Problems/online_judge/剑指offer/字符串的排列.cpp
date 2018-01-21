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
			auto tmp = str[index];
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

int main() {
	string s = "abcd";
	Permutation(s);
	return 0;
}