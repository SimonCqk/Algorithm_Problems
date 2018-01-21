/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/
#include<iostream>
#include<vector>
using std::vector;

class Solution {
public:
	// binary search.
	int findMin(vector<int>& nums) {
		int begin = 0, end = nums.size() - 1;
		while (begin < end) {
			int mid = (begin + end) / 2;
			if (nums[mid] > nums[end])
				begin = mid + 1;
			else
				end = mid;
		}
		return nums[begin];
	}
};

int main() {
	std::vector<int>  v{ 4,5,6,7,0,1,2 };
	Solution s;
	std::cout << s.findMin(v);
}