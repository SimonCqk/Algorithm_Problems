/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
print(nums[i]);
}

*/
#include<vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int cur_dup, count = 0;
		for (auto beg = nums.cbegin(), end = nums.cend();
			beg != end; ++beg) {
			cur_dup = 1;
			auto cur_iter = beg;
			while ((beg + 1) != end && (*beg) == (*(beg + 1))) {
				++cur_dup; ++beg; 
			}
			int to_move = cur_dup > 2 ? 2: cur_dup;
			while (to_move--)
				nums[count++] = *(cur_iter++);
		}
		nums.resize(count);
		return count;
	}
};

int main() {
	Solution s;
	vector<int> nums{ 1,1,1,2,2,3 };
	int ans = s.removeDuplicates(nums);
	std::printf("ans = %d\n", ans);
	for (auto num : nums)
		std::printf("%d ", num);
	std::printf("\n");
	return 0;
}