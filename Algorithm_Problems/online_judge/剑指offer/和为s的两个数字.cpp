/*
  输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
  输出任意一对即可。
*/
#include<vector>

using namespace std;

/*
  O(n^2)的方法太笨了。
  数组是递增排序的，那么分别设两个指针，一个从前往后，一个从后往前，根据当前和
  的大小和目标和比较，动态调整指针位置就可以了。
*/
bool FindSumPair(const vector<int>& nums, const int& sum, int& first, int& second) {
	if (nums.size() < 2)
		return false;
	int start = 0, last = nums.size() - 1;
	int cur_sum;
	while (start < last) {
		cur_sum = nums[start] + nums[last];
		if (cur_sum == sum) {
			first = nums[start];
			second = nums[last];
			return true;
		}
		else if (cur_sum < sum)
			++start;
		else
			--last;
	}
	return false;
}

int main() {
	vector<int> nums{ 1,2,4,7,11,15 };
	int fir, sec;
	if (FindSumPair(nums, 15, fir, sec)) {
		std::printf("%d + %d = 15\n", fir, sec);
	}
	else
		std::printf("Can't find 2 numbers whose sum is 15.");
	return 0;
}