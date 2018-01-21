/*
实现一个函数，把字符串中的每个空格替换成 “%20”
例如：输入 “We are happy.” 则输出 ""We%20are%20happy."
*/

// 时间复杂度为O(n)

#include<string>
#include<iostream>

// char* 版本
void ReplaceBlank(char* str, const int& len) {
	if (!str || len <= 0)
		return;
	int blank_num = 0,old_len=0;
	for (int i = 0; str[i] != '\0'; ++i) {
		++old_len;
		if (str[i] == ' ')
			++blank_num;
	}
	int new_len = old_len + 2 * blank_num;
	if (new_len > len)
		return;
	while (old_len >= 0 && old_len < new_len) {
		if (str[old_len] == ' ') {
			str[new_len--] = '0';
			str[new_len--] = '2';
			str[new_len--] = '%';
			--old_len;
		}
		else {
			str[new_len--] = str[old_len--];
		}
	}
}

void ReplaceBlank(std::string& str) {
	int old_len = str.size();
	int new_len = old_len;
	for (auto beg = str.cbegin(), last = str.cend();
		beg != last; ++beg) {
		if (*beg == ' ')
			new_len += 2;
	}
	str.resize(new_len);
	while (old_len >= 0 && old_len < new_len) {
		if (str[old_len] == ' ') {
			str[new_len--] = '0';
			str[new_len--] = '2';
			str[new_len--] = '%';
			--old_len;
		}
		else {
			str[new_len--] = str[old_len--];
		}
	}
}


int main() {
	char str[20] = "We are happy.";
	ReplaceBlank(str, 20);
	for (int i = 0; str[i] != '\0'; ++i)
		std::cout << str[i];
	std::cout << std::endl;
	std::string str_two = "We are happy.";
	ReplaceBlank(str_two);
	std::cout << str_two << std::endl;
	return 0;
}