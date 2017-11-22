/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]

*/

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		string beg = "";
		vector<string> ans;
		appendNew(ans, beg, n, n);
		return ans;
	}
	void appendNew(vector<string>& ans, string cur, int left, int right) {
		if (left > right)
			return;
		if (!left && !right) {
			ans.push_back(cur);
			return;
		}
		if (left > 0)
			appendNew(ans, cur + "(", left - 1, right);
		if (right > 0)
			appendNew(ans, cur + ")", left, right - 1);
	}
};