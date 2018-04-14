/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
[2,4],
[3,4],
[2,3],
[1,2],
[1,3],
[1,4],
]
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> init;
		combineBackTrace(res, init, n, 1, k);
		return res;
	}
	void combineBackTrace(vector<vector<int>>& res, vector<int>& cur, int n, int index, int k_left) {
		if (!k_left) {
			res.push_back(cur);
			return;
		}
		else {
			for (int i = index; i <= n; ++i) {
				auto new_cur = cur;
				new_cur.push_back(i);
				combineBackTrace(res, new_cur, n, i + 1, k_left - 1);
			}
		}
	}
};

int main() {
	Solution s;
	auto res = s.combine(4, 2);
	for (auto& each : res) {
		for (auto& i : each)
			cout << i << ' ';
		cout << endl;
	}
	return 0;
}