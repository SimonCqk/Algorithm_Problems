/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
#include<string>

using std::string;

class Solution {
public:
	string addBinary(string a, string b) {
		if (a.size() > b.size())
			std::swap(a, b);
		int carry = 0;
		auto a_beg = a.rbegin(), b_beg = b.rbegin();
		auto a_end = a.rend(), b_end = b.rend();
		for (; a_beg != a_end; ++a_beg, ++b_beg) {
			(*b_beg) += (*a_beg) - '0' + carry;
			if (*b_beg > '1') {
				carry = 1;
				*b_beg -= 2;
			}
			else
				carry = 0;
		}
		while (carry&&b_beg != b_end) {
			(*b_beg) += carry;
			if (*b_beg > '1') {
				carry = 1;
				*b_beg -= 2;
			}
			else
				carry = 0;
			++b_beg;
		}
		if (carry&&b_beg == b_end)
			b.insert(0, string("1"));
		return b;
	}
};