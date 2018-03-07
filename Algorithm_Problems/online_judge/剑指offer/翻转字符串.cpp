/*
 1.翻转单词顺序
 输入一个英文句子，翻转句子中单词的顺序，但单词内的字符的顺序不变。
 第一步翻转字符串中所有字符，第二步再翻转每个单词中的顺序。
*/
#include<string>
#include<iostream>

using namespace std;

void Reverse(string& str) {
	// std::reverse(str.begin(),str.end());
	if (str.empty() || str.size() == 1)
		return;
	int start = 0, last = str.size() - 1;
	while (start < last) {
		std::swap(str[start], str[last]);
		++start;
		--last;
	}
}

string ReverseSentence(string str) {
	if (str.empty() || str.size() == 1)
		return std::move(str);
	std::reverse(str.begin(), str.end());
	auto start = str.begin(), last = str.end();
	auto internal_end = start;
	while (start != last && internal_end != last) {
		if (*start == ' ') {
			++start; ++internal_end;
		}
		else if (*internal_end == ' ' || internal_end == last) {
			std::reverse(start, (internal_end - 1));
			start = internal_end;
		}
		else
			++internal_end;
	}
	return std::move(str);
}

/*
 2.左旋转字符串
 把字符串前面若干个字符转移到字符串的尾部。
 如"abcdefg"和2，函数将返回"cdefgab".
 通过前面的启发，我们把字符串变成2部分，ab和cdefg，分别翻转得到bagfedc
 再把翻转后的字符串再次翻转回来，就得到了"cdefgab"
*/
string LeftRotateString(string str, int n) {
	if (str.size() <= 1 || n <= 0 || n >= str.size())
		return std::move(str);
	auto start = str.begin(), last = str.end();
	auto mid = start + n;
	std::reverse(start, mid);
	std::reverse(mid, last);
	std::reverse(start, last);
	return std::move(str);
}


int main() {
	string s = "I am a student";
	cout << ReverseSentence(s) << endl;
	cout << LeftRotateString("abcdefg", 2) << endl;
	return 0;
}