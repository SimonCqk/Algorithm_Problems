/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
[1,1,2],
[1,2,1],
[2,1,1]
]
*/
#include<vector>
#include<algorithm>

using std::vector;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.empty())
			return { {} };
		std::sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		permute_core(ans, nums);
		return ans;
	}

	void permute_core(vector<vector<int>>& ans, vector<int> nums, size_t index = 0) {
		if (index == nums.size())
			ans.push_back(std::move(nums));
		else {
			for (size_t i = index; i < nums.size(); ++i) {
				if (i != index && nums[i] == nums[index])
					continue;
				std::swap(nums[i], nums[index]);
				permute_core(ans, nums, index + 1);
			}
		}
	}
};