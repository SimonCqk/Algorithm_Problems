/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ans;
		size_t ub = nums.size();
		int* dp = new int[ub];
		ans = dp[0] = nums[0];
		for (int i = 1; i < ub; ++i) {
			dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
			ans = std::max(ans, dp[i]);
		}
		return ans;
	}
};