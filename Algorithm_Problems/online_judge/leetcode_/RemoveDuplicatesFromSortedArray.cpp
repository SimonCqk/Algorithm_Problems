/*
Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int size = nums.size();
		if (!size)
			return 0;
		int count = 0;
		for (auto& num : nums) {
			if (num != nums[count]) {
				++count;
				nums[count] = num;
			}
		}
		return ++count;
	}
};