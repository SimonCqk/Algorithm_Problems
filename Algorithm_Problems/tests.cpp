#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> GetTopTen(const vector<int>& nums) {
	vector<int> queue;
	for (int i = 0; i < 10; ++i)
		queue.push_back(nums[i]);
	sort(queue.begin(), queue.end(), [](const int& lhs, const int&rhs) {
		return lhs > rhs;
	});
	int min_in_queue = queue.back();
	for (auto beg = nums.begin() + 10; beg != nums.end(); ++beg) {
		if ((*beg) > min_in_queue) {
			queue.pop_back();
			queue.push_back(*beg);
			sort(queue.begin(), queue.end(), [](const int& lhs, const int&rhs) {
				return lhs > rhs;
			});
			min_in_queue = queue.back();
		}
	}
	return queue;
}

int main() {

	return 0;
}



