/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/
#include<vector>
#include<algorithm>

using std::vector;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> res;
		auto beg = intervals.begin(), last = intervals.end();
		while (beg!=last && beg->end < newInterval.start) {
			res.push_back(*(beg++));
		}
		while (beg!=last && beg->start <= newInterval.end) {
			newInterval.start = std::min(newInterval.start, beg->start);
			newInterval.end = std::max(newInterval.end, beg->end);
			beg++;
		}
		res.push_back(newInterval);
		while (beg!=last) {
			res.push_back(*(beg++));
		}
		return std::move(res);
	}
};