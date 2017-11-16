/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty())
			return {};
		const unordered_map<int, string> map{
			{ 1,"" },{ 2,"abc" },{ 3,"def" },
			{ 4,"ghi" },{ 5,"jkl" },{ 6,"mno" },
			{ 7,"pqrs" },{ 8,"tuv" },{ 9,"wxyz" },
			{ 0,"" }
		};
		//vector<string> map{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		vector<string> ans{ "" };
		for (int i = 0, size = digits.size(); i < size; ++i) {
			int num = digits[i] - '0';
			string candidates = map.at(num);
			if (candidates.empty())
				continue;
			vector<string> tmp;
			for (auto& str : candidates) {
				for (auto& each : ans)
					tmp.push_back(each + str);
			}
			ans.swap(tmp);
		}
		return ans;
	}
};