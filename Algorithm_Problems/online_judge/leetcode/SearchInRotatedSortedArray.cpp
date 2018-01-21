/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

#include<vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty())
			return -1;
		if (nums.size() == 1)
			return nums[0] == target ? 0 : -1;
		int low = 0, high = nums.size() - 1;
		int mid;
		// find dividing point && find target
		while (low < high) {
			mid = (low + high) / 2;
			if (nums[mid] == target)  return mid;
			if (nums[mid] < nums[0])  high = mid;
			else low = mid + 1;
		}
		// `low` is dividing index point
		if (target < nums[0])
			high = nums.size() - 1;
		else {
			high = low; low = 0;
		}
		// find target
		while (low <= high) {
			mid = (low + high) / 2;
			if (nums[mid] == target)  return mid;
			if (nums[mid] < target)	low = mid + 1;
			else  high = mid - 1;
		}
		return -1;
	}
};

int main() {
	Solution s;
	vector<int> vec{ 3,1 };
	auto ans = s.search(vec, 1);
	printf("%d\n", ans);
	return 0;
}