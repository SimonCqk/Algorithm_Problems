/*
  0,1,2...n-1这n个数字排成一圈，从数字0开始，每次从这个圆圈里删除第m个数字。
  求出这个圆圈最后剩下的数字。
*/
#include<list>
// list是一个单链表，用list模拟循环链表，迭代到末尾时重新置位

using namespace std;

int LastRemaining(const int& n, const int& m) {
	if (n < 1 || m < 1)
		return -1;
	list<int> nums;
	for (int i = 0; i < n; ++i)
		nums.push_back(i);
	auto current = nums.begin();
	while (nums.size() > 1) {
		for (int i = 1; i < m; ++i) {  // 第m个数字,即向前走m-1步所在的数字
			++current;
			if (current == nums.end())
				current = nums.begin();
		}
		auto next = ++current;
		if (next == nums.end())
			next = nums.begin();
		--current;
		nums.erase(current);  // list执行erase，迭代器并不会失效
		current = next;
	}
	return (*current);
}

int main() {
	std::printf("%d\n", LastRemaining(5, 3));
	return 0;
}