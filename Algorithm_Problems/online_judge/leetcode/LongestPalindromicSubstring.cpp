/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

class Solution {
public:
	string longestPalindrome(string s) {
		int size = s.size();
		if (size <= 1 || (size == 2 && s[0] == s[1]))
			return s;
		bool check = true;
		for (int i = 1; i < size; ++i) {
			if (s[i - 1] != s[i]) {    // check if all elements are same.
				check = false;
				break;
			}
		}
		if (check)
			return s;
		int max = 0;
		string ans;
		for (int i = 0, j = 1; i < size; ++i, j = i + 1) {
			while (j < size) {
				if (isValid(s, i, j)) {
					if (max < j - i + 1) {
						max = j - i + 1;
						ans = s.substr(i, max);
					}
				}
				++j;
			}
		}
		if (max == 0)
			return s.substr(0, 1);
		return ans;
	}
	bool isValid(const string& s, const int& start, const int& end) {
		for (int i = start, j = end; i < j; ++i, --j) {
			if (s[i] != s[j])
				return false;
		}
		return true;
	}
};