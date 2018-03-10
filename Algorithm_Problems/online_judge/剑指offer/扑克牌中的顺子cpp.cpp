/*
  从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
  2~10为数字本身，A为1，J为11，Q为12，K为13，大小王为任意数字（大小王表示为0）。
*/
#include<vector>
#include<algorithm>

using namespace std;

bool IsContinuous(const vector<int>& nums) {
	if (nums.empty())
		return false;
	std::sort(nums.begin(), nums.end());
	int zero_num = 0, gap_num = 0;
	for (const int& num : nums)  // 统计数组中0的个数
		if (num == 0)
			++zero_num;
	int small = zero_num;
	int big = small + 1;
	while (big < nums.size()) {
		if (nums[small] == nums[big]) // 有对子
			return false;
		gap_num += nums[big] - nums[small] - 1;  // 计算间隔数目
		small = big++;
	}
	return gap_num <= zero_num;
}