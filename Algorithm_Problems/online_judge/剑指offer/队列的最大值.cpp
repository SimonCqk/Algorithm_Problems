/*
  1.滑动窗口的最大值
  给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。
  一个滑动窗口可以看成是一个队列，窗口滑动时，处于窗口的第一个数字先被删除，同时在
  窗口的末尾添加一个新的数字。先进先出。
*/
#include<vector>
#include<deque>
#include<iostream>

using namespace std;

vector<int> MaxInWindows(const vector<int>& nums, int size) {
	vector<int> max_in_win;
	if (nums.size() > size&&size >= 1) {
		deque<int> index;  // 保存可能是窗口最大值的数字所在下标
		for (int i = 0; i < size; ++i) {
			while (!index.empty() && nums[index.back()] < nums[i])
				index.pop_back();
			index.push_back(i);
		}
		for (int i = size; i < nums.size(); ++i) {
			max_in_win.push_back(index.front());  // 最大值永远在队列头
			while (!index.empty() && nums[index.back()] < nums[i])  // 弹出不可能是最大值的数
				index.pop_back();
			if (!index.empty() && index.front() + size <= i)
				index.pop_front();  // 滑动窗口后移
			index.push_back(i);
		}
		max_in_win.push_back(nums[index.front()]);
	}
	return std::move(max_in_win);
}