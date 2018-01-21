/*
 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 例如，字符串"+100","5e2","-123","3.1416"及"-1E-16",都表示数值，
 但"12e","1a3.14","1.2.3","+-5"及"12e+5.4"都不是。
*/
#include<string>
#include<iostream>

using namespace std;

bool AfterE(const string& str) {
	if (str.empty())
		return false;
	size_t has_sign = 0;
	for (const char& ch : str) {
		if (ch == '+' || ch == '-') {
			++has_sign; continue;
		}
		if (!(ch >= '0'&&ch <= '9'&&has_sign <= 1))
			return false;
	}
	return true;
}

bool AfterDot(const string& str) {
	if (str.empty())
		return false;
	for (const char& ch : str) {
		if (!(ch >= '0'&&ch <= '9'))
			return false;
	}
	return true;
}

bool IsNumeric(const string& str) {
	if (str.empty() || str[0] == 'e' || str[0] == 'E')
		return false;
	size_t has_sign = 0;
	for (size_t i = 0; i < str.size(); ++i) {
		if (str[i] == '+' || str[i] == '-') {
			++has_sign; continue;
		}
		if (str[i] == 'e' || str[i] == 'E')
			return AfterE(str.substr(i + 1));
		if (str[i] == '.')
			return AfterDot(str.substr(i + 1));
		if (!(str[i] >= '0'&&str[i] <= '9'&&has_sign <= 1))
			return false;
	}
	return true;
}

int main() {
	string s = "1";
	cout << IsNumeric(s) << endl;
	return 0;
}