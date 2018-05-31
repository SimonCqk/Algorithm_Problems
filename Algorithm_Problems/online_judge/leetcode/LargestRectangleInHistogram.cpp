/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,

find the area of largest rectangle in the histogram.

https://leetcode.com/static/images/problemset/histogram.png

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

https://leetcode.com/static/images/problemset/histogram_area.png

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int size = heights.size();
		int max_area = 0, lowest = std::numeric_limits<int>::max();
		for (int i = 0; i < size; ++i) {
			lowest = std::min(lowest, heights[i]);
			int tmp = 1;
			for (int j = i + 1; j < size && heights[i] <= heights[j]; ++j) {
				++tmp;
			}
			for (int j = i - 1; j >= 0 && heights[i] <= heights[j]; --j) {
				++tmp;
			}
			max_area = std::max(max_area, std::max(lowest*(i + 1), tmp*heights[i]));
		}
		return max_area;
	}
};

int main() {
	vector<int> heights{ 2,1,5,6,2,3 };
	Solution s;
	std::printf("%d\n", s.largestRectangleArea(heights));
	return 0;
}