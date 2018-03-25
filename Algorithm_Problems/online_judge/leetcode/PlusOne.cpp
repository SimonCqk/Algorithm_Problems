/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/
#include<vector>

using std::vector;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int carry = 1;
		for (auto last = digits.rbegin(), beg = digits.rend(); last != beg; ++last) {
			(*last) += carry;
			if ((*last) >= 10) {
				carry = 1;
				(*last) %= 10;
			}
			else {
				carry = 0; break;
			}
		}
		if (carry)
			digits.insert(digits.begin(), carry);
		return digits;
	}
};