/*
实现一个函数按照之字形顺序打印二叉树，即第一行从左到右顺序打印，第二行从右到左，
第三行再从左到右，以此类推。

                        1
					  2   3
					4  5 6  7
				8 9 10 11 12 13 14 15 
以上二叉树，打印顺序：
1 
3 2
4 5 6 7
15 14 13 12 11 10 9 8

*/
#include"predefines.h"
#include<stack>

using namespace std;

void PrintInSpecialOrder(BinaryNode<int>* root) {
	if (!root)
		return;
	int cur = 0, next = 1;
	stack<BinaryNode<int>*> levels[2];
	levels[cur].push(root);
	while (!levels[0].empty() || !levels[1].empty()) {
		auto node = levels[cur].top();
		levels[cur].pop();
		std::printf("%d ", node->value);
		if (cur == 0) {  // 从左到右的顺序入栈，从右到左的顺序打印
			if (node->left)
				levels[next].push(node->left);
			if (node->right)
				levels[next].push(node->right);
		}
		else {  // 从右到左的顺序入栈，从左到右的顺序打印
			if (node->right) 
				levels[next].push(node->right);
			if (node->left)
				levels[next].push(node->left);
		}
		if (levels[cur].empty()) {
			printf("\n");
			cur = 1 - cur; // 在0和1之间转换
			next = 1 - next; // 同上
		}
	}
}

int main() {
	vector<int> tree{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	BinaryNode<int>* root = new BinaryNode<int>;
	BuildBTree(&root, tree);
	PrintInSpecialOrder(root);
	DestoryBTree(&root);
	return 0;
}