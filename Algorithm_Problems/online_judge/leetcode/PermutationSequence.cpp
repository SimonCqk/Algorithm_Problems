/*
The set [1,2,3,бн,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/
#include<string>
#include<vector>

using std::string;
using std::vector;

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> nums(n, 0);
		for (int i = 1; i <= n; ++i)
			nums[i - 1] = i;
		int count = 1, pos = n - 1, end = pos;
		if (count == k) {
			string ans;
			for (int& num : nums)
				ans.push_back(num + '0');
			return std::move(ans);
		}
		int next;
		while (pos > 0) {
			next = pos;
			--pos;
			if (nums[pos] < nums[next]) {
				int min = end;
				while (nums[min] <= nums[pos])  // find first num larger than nums[pos]
					--min;
				std::swap(nums[min], nums[pos]);
				std::reverse(nums.begin() + next, nums.end());
				++count;
				if (count == k) {
					string ans;
					for (int& num : nums)
						ans.push_back(num + '0');
					return std::move(ans);
				}
				pos = end;  // back to end
			}
		}
		return "";
	}
};
