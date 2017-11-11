/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "a*") ¡ú true
isMatch("aa", ".*") ¡ú true
isMatch("ab", ".*") ¡ú true
isMatch("aab", "c*a*b") ¡ú true

*/
#include<string>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		if (p == ".*")
			return true;
		auto reg = p.cbegin();
		auto ch = s.cbegin();
		for (; ch != s.cend(); ++ch) {
			if (*ch == *reg||(*ch != *reg&&*reg == '.')) {
				++reg;
				continue;
			}
			if (*ch!=*reg) {
				if (*(reg + 1) == '*') {
					++reg;
					continue;
				}

			}

		}
	}
};