/*
不分行从上到下打印二叉树(层序遍历)
*/
#include"predefines.h"
#include<queue>

using namespace std;

// 树是图的一种特殊退化形式，本质就是广度优先遍历二叉树
void PrintByLevelOrder(BinaryNode<int>* root) {
	queue<BinaryNode<int>*> q;
	q.push(root);
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		std::cout << cur->value << ' ';
		if (cur->left)
			q.push(cur->left);
		if (cur->right)
			q.push(cur->right);
	}
	std::cout << std::endl;
}

int main() {
	BinaryNode<int>* root = new BinaryNode<int>;
	vector<int> arr{ 8,6,10,5,7,9,11 };
	BuildBTree(&root, arr);
	PrintByLevelOrder(root);
	DestoryBTree(&root);
	return 0;
}