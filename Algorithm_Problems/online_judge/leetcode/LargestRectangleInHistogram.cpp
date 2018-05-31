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
#include<stack>
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

	int largestRectangleArea(vector<int> heights) {
		// much faster and elegant than the above one

		// push back a extra element stands for the right index of last height
		heights.push_back(0);
		int size = heights.size(), max_area = 0;
		// this stack contains the left elements of 'current height'.
		// the index on the top of stack is the first index on the left higher than 
		// current height.
		stack<int> index;
		for (int i = 0; i < size; i++) {
			// if current height is higher than the bar on the top of stack
			while (!index.empty() && heights[index.top()] >= heights[i]) {
				int h = heights[index.top()];
				index.pop();

				int sidx = index.size() > 0 ? index.top() : -1;
				if (h * (i - sidx - 1) > max_area)
					max_area = h * (i - sidx - 1);
			}
			index.push(i);
		}
		return max_area;
	}
};
