/*
  一个长度为n-1的递增排序数组中所有数字都是唯一的，并且每个数字都在范围0~n-1内。
  在范围0~n-1的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
*/
#include<vector>

using namespace std;

/*
  最直接的方法就是利用n(n-1)/2的公式求出n个数字之和，再减去数组所有数字之和即是缺失的数字。
  时间复杂度为O(n)且没有利用递增数组的特性。
  若缺失数字为k，则0...k-1的数字即是它的下标，那么就转化为了寻找数组中第一个值与下标不相同的数字。
  "在排序数组中查找数字"的变形。
*/

int GetMissingNumber(const vector<int>& nums) {
	if (nums.empty())
		return -1;
	int start = 0, end = nums.size() - 1;
	int mid = (start + end) / 2;
	while (start < end) {
		if (nums[mid] != mid) {
			if (mid == 0 || nums[mid - 1] == mid - 1)
				break;
			else
				end = mid;
		}
		else
			start = mid + 1;
		mid = (start + end) / 2;
	}
	return mid;
}

int main() {
	vector<int> nums{ 0,1,2,3,4,5,7,8,9 };
	std::printf("%d\n", GetMissingNumber(nums));
	return 0;
}