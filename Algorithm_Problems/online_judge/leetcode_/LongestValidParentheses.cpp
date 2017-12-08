/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.empty() || s.size() == 1)
			return 0;
		int size = s.size();
		int max = 0;
		vector<int> longest(size, 0);
		for (int i = 1; i < size; ++i) {
			if (s[i] == ')' && s[i - longest[i - 1] - 1] == '(') {
				longest[i] = longest[i - 1] + 2 + ((i - longest[i - 1] - 2 >= 0) ? longest[i - longest[i - 1] - 2] : 0);
				max = std::max(max, longest[i]);
			}
		}
		return max;
	}

};