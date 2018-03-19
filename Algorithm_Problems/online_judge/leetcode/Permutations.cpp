/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
*/
#include<vector>
#include<utility>

using std::vector;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.empty())
			return { {} };
		vector<vector<int>> ans;
		permute_core(ans, nums);
		return ans;
	}

	void permute_core(vector<vector<int>>& ans, vector<int> nums, size_t index = 0) {
		if (index == nums.size())
			ans.push_back(std::move(nums));
		else {
			for (size_t i = index; i < nums.size(); ++i) {
				std::swap(nums[i], nums[index]);
				permute_core(ans, nums, index + 1);
				std::swap(nums[i], nums[index]);
			}
		}
	}
};