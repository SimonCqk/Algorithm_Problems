/*
Write a function to find the longest common prefix string amongst an array of strings.

*/

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		else if (strs.size() == 1)
			return strs[0];
		if (strs[0][0] != strs[1][0])
			return "";
		string res = strs[0];
		int size = strs.size();
		for (int i = 1; i < size; ++i) {
			int _size = strs[i].size();
			if (_size < res.size())
				res = res.substr(0, _size);
			for (int j = 0; j < _size; ++j) {
				if (res[j] != strs[i][j]) {
					res = res.substr(0, j);
					break;
				}
				if (j == _size - 1)
					res = strs[i];
			}
		}
		return res;
	}
};