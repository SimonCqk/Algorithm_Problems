/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]
*/
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> subs{ {} };
		for (int i = 0; i < nums.size(); i++) {
			int n = subs.size();
			for (int j = 0; j < n; j++) {
				subs.push_back(subs[j]);
				subs.back().push_back(nums[i]);
			}
		}
		sort(subs.begin(), subs.end());
		subs.erase(std::unique(subs.begin(), subs.end()), subs.end());
		return subs;
	}
};