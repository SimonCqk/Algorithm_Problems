/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
*/
#include<vector>
#include<numeric>

using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int start = 0, end = nums.size() - 1, mid;
		while (start <= end) {
			while (start + 1 < nums.size() && nums[start + 1] == nums[start])
				++start;
			while (end > 0 && nums[end - 1] == nums[end])
				--end;
			mid = (start + end) / 2;
			if (nums[mid] == target)
				return true;
			else if (nums[start] <= nums[mid]) {
				if ((nums[start] <= target) && (nums[mid] > target))
					end = mid;
				else
					start = mid + 1;
			}
			else {
				if ((nums[mid] < target) && (nums[end] >= target))
					start = mid + 1;
				else
					end = mid;
			}
		}
		return false;
	}
};