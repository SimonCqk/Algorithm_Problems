/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.size() == 0)
			return {};
		std::sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs) {
			return lhs.start < rhs.start;
		});
		int size = intervals.size();
		vector<Interval> ans;
		ans.push_back(intervals[0]);
		for (int i = 1; i < size; ++i) {
			if (ans.back().end < intervals[i].start)
				ans.push_back(intervals[i]);
			else
				ans.back().end = std::max(ans.back().end, intervals[i].end);
		}
		return ans;
	}
};