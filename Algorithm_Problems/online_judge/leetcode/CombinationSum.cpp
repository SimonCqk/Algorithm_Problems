/*
  Given a set of candidate numbers (C) (without duplicates) and a target number (T),
  find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
  [7],
  [2, 2, 3]
]
*/
#include<vector>
#include<algorithm>

using std::vector;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.empty())
			return { {} };
		std::sort(candidates.begin(), candidates.end());
		vector<vector<int>> ans;
		vector<int> combine;
		backTrack(candidates, target, ans, combine, 0);
		return ans;
	}
private:
	void backTrack(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int begin) {
		if (!target) {
			ans.push_back(combine);
			return;
		}
		else {
			for (int i = begin; i < candidates.size() && candidates[i] <= target; ++i) {
				combine.push_back(candidates[i]);
				backTrack(candidates, target - candidates[i], ans, combine, i);
				combine.pop_back();
			}
		}
	}
};

/*
def combinationSum(self, candidates, target):
res = []
candidates.sort()
self.dfs(candidates, target, 0, [], res)
return res

def dfs(self, nums, target, index, path, res):
if target < 0:
return  # backtracking
if target == 0:
res.append(path)
return
for i in xrange(index, len(nums)):
self.dfs(nums, target-nums[i], i, path+[nums[i]], res)
*/

class Solution1 {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.empty())
			return { {} };
		std::sort(candidates.begin(), candidates.end());
		vector<vector<int>> ans;
		vector<int> combine;
		dfs(candidates, target, ans, combine, 0);
		return ans;
	}
private:
	void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& path, int index) {
		if (target < 0)
			return;
		else if (target == 0) {
			ans.push_back(path);
			return;
		}
		for (int i = index; i < candidates.size() && candidates[i] <= target; ++i) {
			vector<int> cur_path = path;
			cur_path.push_back(candidates[i]);
			dfs(candidates, target - candidates[i], ans, cur_path, i);
		}
	}
};