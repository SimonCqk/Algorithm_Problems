/*
模拟实现std::atoi, 把一个字符串转换成一个整数
*/
#include<string>

enum class Status
{
	invalid,
	valid
};

Status status;

int StrToInt(const std::string& str) {
	status = Status::valid;
	long long num = 0;
	if (str.empty()) {
		status = Status::invalid;
		return 0;
	}
	// 跳过前缀的空字符
	auto beg = str.begin(), end = str.end();
	while (*beg == ' ')
		++beg;
	bool minus = false;
	if (*beg == '+')
		++beg;
	else if (*beg == '-') {
		minus = true;
		++beg;
	}
	while (beg != end) {
		if (*beg >= '0'&&*beg <= '9') {
			num = 10 * num + (*beg++ - '0');
			// 判断是否整形溢出，最大正整数为0X7FFFFFFF，最小负整数为0X80000000
			if (num > 0x7FFFFFFF || num < static_cast<int>(0x80000000)) {
				status = Status::invalid;
				return 0;
			}
		}
		else {
			status = Status::invalid;
			return 0;
		}
	}
	if (minus)
		num *= -1;
	return static_cast<int>(num);
}

int main() {
	std::printf("%d\n", StrToInt(" 1231234"));
	std::printf("%d\n", StrToInt("+1234"));
	std::printf("%d\n", StrToInt("-123654"));
	std::printf("%d\n", StrToInt("as123d123"));
	return 0;
}