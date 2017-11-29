/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1
*/

// view solution : https://leetcode.com/problems/next-permutation/solution/

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (isDescend(nums)) {
			std::sort(nums.begin(), nums.end());
			return;
		}
		int size = nums.size();
		int index = size - 1;

		while (index > 0 && nums[index] <= nums[index - 1])// find first descend num.
			--index;
		--index;
		// find the element just larger than nums[index] among right of nums[index].
		if (index >= 0) {
			int idx_larger = size - 1;
			while (idx_larger >= index && nums[idx_larger] <= nums[index])
				--idx_larger;
			swap(nums[index], nums[idx_larger]);
		}
		// reverse the right of nums[index]
		for (--size, ++index; index < size; ++index, --size)
			swap(nums[index], nums[size]);
	}
	bool isDescend(const vector<int>& nums) {
		auto beg = nums.cbegin() + 1, end = nums.cend();
		for (; beg != end; ++beg) {
			if (*beg > *(beg - 1))
				return false;
		}
		return true;
	}
};