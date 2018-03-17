/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/
#include<vector>

using std::vector;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		// put all positive elements to its proper positions
		// let positive elements n locate in nums[n-1]
		// the first invalid index is the number we want (index + 1 is what missed)
		for (int i = 0; i < nums.size(); ++i) {
			while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
				std::swap(nums[i], nums[nums[i] - 1]);
		}
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] != i + 1)
				return i + 1;
		return nums.size() + 1;
	}
};