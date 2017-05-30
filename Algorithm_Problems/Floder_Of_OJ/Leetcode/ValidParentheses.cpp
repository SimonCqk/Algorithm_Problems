/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Subscribe to see which companies asked this question.
*/
#include<stack>
using std::stack;
using std::string;

class Solution {
public:
	bool isValid(string s) {
		stack<char> items;
		for (auto& c : s) {
			switch (c)
			{
			case '(':
			case '[':
			case '{':
				items.push(c); break;
			case ')':
				if (items.empty() || items.top() != '(')return false;
				else items.pop(); break;
			case ']':
				if (items.empty() || items.top() != '[')return false;
				else items.pop(); break;
			case '}':
				if (items.empty() || items.top() != '{')return false;
				else items.pop(); break;
			default:
				break;
			}
		}
		return items.empty();
	}
};