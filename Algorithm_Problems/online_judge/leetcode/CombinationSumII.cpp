/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C
where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/
#include<vector>
#include<algorithm>

using std::vector;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		if (candidates.empty())
			return { {} };
		vector<vector<int>> ans;
		std::sort(candidates.begin(), candidates.end());
		vector<int> path;
		backTrack(candidates, target, ans, path);
		return ans;
	}
private:
	void backTrack(const vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& path, int index = 0) {
		if (!target) {
			ans.push_back(path);
		}
		else if (target > 0) {
			for (int i = index; i < candidates.size() && candidates[i] <= target; ++i) {
				path.push_back(candidates[i]);
				backTrack(candidates, target - candidates[i], ans, path, i + 1);
				path.pop_back();
				while (i < candidates.size() && candidates[i] == candidates[i + 1])
					++i;
			}
		}
	}
};

int main() {
	Solution s;
	vector<int> candidates{ 10, 1, 2, 7, 6, 1, 5 };
	auto ans = s.combinationSum2(candidates, 8);
	for (auto each : ans) {
		for (auto i : each) {
			std::printf("%d ", i);
		}
		std::printf("\n");
	}
	return 0;
}