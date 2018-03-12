/*
  假设把某股票的价格按时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润
  是多少？
  即求这个数组中两个元素的最大差值。
*/
#include<vector>

using namespace std;

int MaxProfit(const vector<int>& nums) {
	if (nums.size() < 2)
		return 0;
	int min = nums[0];
	int max_profit = nums[1] - min;
	for (int i = 2; i < nums.size(); ++i) {
		min = (nums[i - 1] < min) ? (nums[i - 1]) : min;
		max_profit = (nums[i] - min) > max_profit ? (nums[i] - min) : max_profit;
	}
	return max_profit;
}

int main() {
	vector<int> nums{ 9,11,8,5,7,12,16,14 };
	std::printf("%d\n", MaxProfit(nums));
	return 0;
}