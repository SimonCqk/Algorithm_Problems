/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates
*/

class Solution {
public:
	int findMin(vector<int>& nums) {
		int begin = 0, end = nums.size() - 1;
		while (begin < end) {
			int mid = (begin + end) / 2;
			if (nums[mid] > nums[end])
				begin = mid + 1;
			else if (nums[mid] < nums[end])
				end = mid;
			else
				--end;
		}
		return nums[begin];
	}
};