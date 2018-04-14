/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]
*/
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> subs(1, vector<int>());
		for (int i = 0; i < nums.size(); i++) {
			int n = subs.size();
			for (int j = 0; j < n; j++) {
				subs.push_back(subs[j]);
				subs.back().push_back(nums[i]);
			}
		}
		return subs;
	}
};

int main() {
	Solution s;
	vector<int> nums{ 1,2,3 };
	auto res = s.subsets(nums);
	for (auto& each : res) {
		for (auto& i : each)
			cout << i << ' ';
		cout << endl;
	}
	return 0;
}