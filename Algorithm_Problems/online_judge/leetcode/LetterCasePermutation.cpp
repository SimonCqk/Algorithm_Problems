/*
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]

Note:

S will be a string with length at most 12.
S will consist only of letters or digits.
*/
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<string> letterCasePermutation(string S) {
		vector<string> res;
		res.push_back(S);
		backTrace(res, S, 0);
		return res;
	}
	void backTrace(vector<string> &res, string& s,int index) {
		if (index == s.size())
			return;
		else {
			for (int i = index; i < s.size(); ++i) {
				if ('0' <= s[i] && s[i] <= '9')
					continue;
				else if ('a' <= s[i] && s[i] <= 'z') {
					s[i] -= 32;
					res.push_back(s);
					backTrace(res, s, i + 1);
					s[i] += 32;	
				}
				else if ('A' <= s[i] && s[i] <= 'Z') {
					s[i] += 32;
					res.push_back(s);
					backTrace(res, s, i + 1);
					s[i] -= 32;
				}
			}
		}
	}
};