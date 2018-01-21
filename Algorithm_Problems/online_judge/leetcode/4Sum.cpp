/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]
*/
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		// judge if all 0.
		int jd = 0;
		for (auto& item : nums)
			jd |= item;
		if (!jd&&target)
			return {};
		set<vector<int>> ans_set;
		if (nums.size() == 4) {
			int sum = accumulate(nums.begin(), nums.end(), 0);
			if (sum == target)
				ans_set.insert(nums);
			return vector<vector<int>>(ans_set.begin(), ans_set.end());
		}
		sort(nums.begin(), nums.end());
		int left, first = 0, right = nums.size() - 1;
		for (; first < right - 2; ++first) {
			for (left = first + 1; left < right - 1; ++left) {
				int dest = target - nums[first] - nums[left];
				for (int i = left + 1, j = right; i < j; ) {
					int sum = nums[i] + nums[j];
					if (sum > dest)
						--j;
					else if (sum < dest)
						++i;
					else {
						int m = nums[i], n = nums[j];
						vector<int> three = { nums[first],nums[left],m,n };
						ans_set.insert(three);
						while (i < j && nums[i] == m)
							i++;
						while (i < j && nums[j] == n)
							j--;
					}
				}
				while (left < right && nums[left] == nums[left + 1])
					++left;
			}
		}
		return vector<vector<int>>(ans_set.begin(), ans_set.end());
	}
}
};