/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
["aa","b"],
["a","a","b"]
]
*/
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> ans;
		vector<string> cur;
		dfs(ans, cur, s, 0);
		return ans;
	}
	void dfs(vector<vector<string>>& ans, vector<string>& cur, const string& str, int start) {
		if (start == str.size()) {
			ans.push_back(cur);
			return;
		}
		else {
			for (int i = start; i < str.size(); ++i) {
				if (isPalindrome(str, start, i)) {
					cur.push_back(str.substr(start, i - start + 1));
					dfs(ans, cur, str, i + 1);
					cur.pop_back();  // trace back.
				}
			}
		}
	}
private:
	bool isPalindrome(const string& str, size_t start, size_t end) {
		while (start < end) {
			if (str[start] != str[end])
				return false;
			++start; --end;
		}
		return true;
	}
};