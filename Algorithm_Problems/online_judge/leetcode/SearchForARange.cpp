/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty())
			return { -1,-1 };
		int start = 0, end = nums.size() - 1;
		int mid;
		// find start first
		while (start <= end) {
			mid = (start + end) / 2;
			if (nums[mid] < target)
				start = mid + 1;
			else if (nums[mid] > target)
				end = mid - 1;
			else {
				while (mid > 0 && nums[mid - 1] == nums[mid])
					--mid;
				break;
			}
		}
		if (nums[mid] != target)  // target not found
			return { -1,-1 };
		// then find end 
		int left = mid;
		start = mid; end = nums.size() - 1;
		while (start <= end) {
			mid = (start + end) / 2;
			if (nums[mid] < target)
				start = mid + 1;
			else if (nums[mid] > target)
				end = mid - 1;
			else {
				while (mid + 1 < nums.size() && nums[mid + 1] == nums[mid])
					++mid;
				break;
			}
		}
		return { left,mid };
	}
};