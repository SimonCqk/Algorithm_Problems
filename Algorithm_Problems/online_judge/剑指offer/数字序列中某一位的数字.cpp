/*
  数字以01234567891011121314...的格式序列化到一个字符序列中。
  请编写一个函数，求任意第n位对应的数字。
*/
#include<cmath>
#include<iostream>

int CountOfInt(int digit) { // n位的数总共有多少个
	if (digit == 1)
		return 10;
	return 9 * static_cast<int>(std::pow(10, digit - 1));
}

int DigitAtIndex(int index, int digit) {  // digit: 整数的位数
	int begin;
	if (digit == 1)
		begin = 0;
	else
		begin = static_cast<int>(std::pow(10, digit - 1));
	int number = begin + index / digit;
	int right_index = digit - index % digit;
	for (int i = 1; i < right_index; ++i)
		number /= 10;
	return number % 10;
}

int DigitAtIndex(int index) {
	if (index < 0)
		return -1;
	int digit = 1;
	while (true) {
		int number = CountOfInt(digit);
		if (index < digit*number)
			return DigitAtIndex(index, digit);
		index -= digit * number;
		++digit;
	}
	return -1;
}

int main() {
	std::cout << DigitAtIndex(1001) << std::endl;
	return 0;
}