/*
  输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
*/
#include"predefines.h"

bool VerifySequenceOfBST(const vector<int>& seq) {
	if (seq.empty())
		return false;
	int size = seq.size();
	int root = seq[size - 1];
	// 左子树的值都小于根节点,寻找左子树
	int left = 0;
	for (; left < size - 1; ++left)
		if (seq[left] > root)
			break;
	int right = left;
	for (; right < size - 1; ++right)
		if (seq[right] < root)
			return false;
	// 判断左子树是否是二叉搜索树
	bool leftans = true;
	if (left > 0)
		leftans = VerifySequenceOfBST(vector<int>(seq.begin(), seq.begin() + left));
	// 判断右子树是否是二叉搜索树
	bool rightans = true;
	if (right < size - 1)
		rightans = VerifySequenceOfBST(vector<int>(seq.begin() + left, seq.begin() + right));
	return left && right;
}

int main() {
	//vector<int> sample{ 5,7,6,9,11,10,8 };
	vector<int> sample{ 7,4,5,6 };
	cout << VerifySequenceOfBST(sample) << endl;
	return 0;
}