/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
["ate", "eat","tea"],
["nat","tan"],
["bat"]
]
Note: All inputs will be in lower-case.
*/
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> map;
		string s;
		for (string str : strs) {
			s = str;
			std::sort(s.begin(), s.end());
			map[s].push_back(str);
		}
		vector<vector<string>> ans;
		for (auto str_vec : map) {
			ans.push_back(str_vec.second);
		}
		return ans;
	}
};