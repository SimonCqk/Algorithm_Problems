/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]
*/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int left = 0, right = nums.size() - 1;
		set<vector<int>> ans_set;
		for (; left < right; ++left) {
			int dest = -nums[left];
			for (int i = left + 1, j = right; i < j; ) {
				int sum = nums[i] + nums[j];
				if (sum > dest)
					--j;
				else if (sum < dest)
					++i;
				else {
					int m = nums[i], n = nums[j];
					vector<int> three{ m,n,-dest };
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
		vector<vector<int>> ans(ans_set.begin(), ans_set.end());
		return ans;
	}
};