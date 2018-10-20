/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/
#include<string>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		for (auto beg = s.begin(), end = s.end() - 1; beg < end;) {
			if (!isalpha(*beg) && !isdigit(*beg)) {
				++beg; continue;
			}
			if (!isalpha(*end) && !isdigit(*end)) {
				--end; continue;
			}
			if (!(toLower(*beg) == toLower(*end))) return false;
			++beg; --end;
		}
		return true;
	}
	char toLower(char c) {
		if (c >= 'A'&&c <= 'Z') {
			c += 32;
		}
		return c;
	}
};