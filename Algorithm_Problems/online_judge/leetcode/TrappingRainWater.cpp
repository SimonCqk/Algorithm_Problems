/*
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
#include<vector>

using std::vector;

class Solution {
public:
	int trap(vector<int>& height) {
		if (height.empty())
			return 0;
		int trapped = 0;
		auto beg = height.begin(), last = height.end()-1;
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