/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该
栈的弹出序列。假设压入栈的所有数字均不相等。
*/
#include<vector>
#include<stack>

using namespace std;

bool IsPopOrder(const vector<int>& seq, const vector<int>& sample) {
	if (seq.empty() || sample.empty())
		return false;
	auto seqbegin = seq.cbegin(), sambegin = sample.cbegin();
	stack<int> s;
	s.push(*(seqbegin++));
	while (sambegin != sample.cend()) {
		while (s.top() != (*sambegin)&& seqbegin != seq.cend())
			s.push(*(seqbegin++));
		if (!s.empty()&&s.top()==(*sambegin)) {
			s.pop();
			++sambegin;
		}
		else
			break;
	}
	return sambegin == sample.cend();
}

int main() {
	vector<int> seq{ 1,2,3,4,5 };
	vector<int> sample{ 3,4,2,5,1 };
	printf("%d\n", IsPopOrder(seq, sample));
	return 0;
}