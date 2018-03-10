/*
Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
Note:

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
*/
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		vector<vector<int>> points{ p1,p2,p3,p4 };
		std::sort(points.begin(), points.end(), [](const vector<int>& l, const vector<int>& r) {
			if (l[0] == r[0])
				return l[1] < r[1];
			else
				return l[0] < r[0];
		});
		int diagonal1 = std::pow(points[1][0] - points[0][0], 2) + std::pow(points[1][1] - points[0][1], 2);
		int diagonal2 = std::pow(points[2][0] - points[0][0], 2) + std::pow(points[2][1] - points[0][1], 2);
		int adjacent1 = std::pow(points[3][0] - points[0][0], 2) + std::pow(points[3][1] - points[0][1], 2);
		int adjacent2 = std::pow(points[2][0] - points[1][0], 2) + std::pow(points[2][1] - points[1][1], 2);
		return (diagonal1 == diagonal2) && (diagonal1 != 0) && (adjacent1 == adjacent2) && (adjacent1 != 0);
	}
};