/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int left = 0, right = nums.size() - 1;
		int ans = accumulate(nums.begin(), nums.begin() + 3, 0);
		int min = abs(target - ans);
		for (; left < right; ++left) {

			for (int i = left + 1, j = right; i < j;) {
				int sum = nums[left] + nums[i] + nums[j];
				int dist = abs(target - sum);
				if (sum == target)
					return sum;
				if (dist < min) {
					min = dist;
					ans = sum;
				}
				if (sum > target)
					--j;
				else
					++i;
			}
		}
		return ans;
	}
};