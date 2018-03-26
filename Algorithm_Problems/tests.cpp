#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<set>

using namespace std;

int Solve(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());
	set<vector<int>> ans;
	for (auto beg = nums.begin(), last = nums.end(); beg != last; ++beg) {
		for (auto cur = beg + 1; cur != last && (*cur - *beg) <= k; ++cur) {
			if (*cur - *beg == k) {
				ans.insert({*cur,*beg});
			}
		}
		while (beg + 1 != last && *(beg + 1) == (*beg))
			++beg;
	}
	return ans.size();
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> nums;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		nums.push_back(num);
	}
	cout << Solve(nums, k) << endl;
	return 0;
}