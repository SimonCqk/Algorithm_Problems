/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
#include<string>

using std::string;

class Solution {
public:
	string multiply(string num1, string num2) {
		string ans(num1.size() + num2.size(), '0');
		int carry, tmp;
		for (int i = num1.size() - 1; i >= 0; --i) {
			carry = 0;
			for (int j = num2.size() - 1; j >= 0; --j) {
				tmp = ans[i + j + 1] - '0' + (num2[j] - '0')*(num1[i] - '0') + carry;
				ans[i + j + 1] = tmp % 10 + '0';
				carry = tmp / 10;
			}
			ans[i] += carry;
		}
		size_t start = ans.find_first_not_of('0');
		if (start != string::npos)
			return std::move(ans.substr(start));
		return "0";
	}
};