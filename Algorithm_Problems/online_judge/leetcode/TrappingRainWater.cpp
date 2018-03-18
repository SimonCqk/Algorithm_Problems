/*
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
#include<vector>
#include<algorithm>

using std::vector;

class Solution {
public:
	int trap(vector<int>& height) {
		if (height.empty())
			return 0;
		int trapped = 0;
		auto beg = height.begin(), last = height.end() - 1;
		int max_left = 0, max_right = 0;
		while (beg != last) {
			if (*beg <= *last) {
				if (*beg > max_left)
					max_left = *beg;
				else
					trapped += max_left - *beg;
				++beg;
			}
			else {
				if (*last > max_right)
					max_right = *last;
				else
					trapped += max_right - *last;
				--last;
			}
		}
		return trapped;
	}
};

/*
  Dynamic programming solution:
  1.iterate from left to right, find left_max array.
  2.iterate from right to left, find right_max array.
  3.the overlap area is trapped area.
*/
class SolutionDp {
public:
	int trap(vector<int>& height) {
		if (height.empty())
			return 0;
		int trapped = 0;
		vector<int> left_max(height.size(), 0), right_max(height.size(), 0);
		left_max[0] = height[0], right_max[height.size() - 1] = height[height.size() - 1];
		for (int i = 1; i < height.size(); ++i)
			left_max[i] = std::max(height[i], left_max[i - 1]);
		for (int i = height.size() - 2; i >= 0; --i)
			right_max[i] = std::max(height[i], right_max[i + 1]);
		for (int i = 0; i < height.size(); ++i)
			trapped += std::min(left_max[i], right_max[i]) - height[i];
		return trapped;
	}
};
