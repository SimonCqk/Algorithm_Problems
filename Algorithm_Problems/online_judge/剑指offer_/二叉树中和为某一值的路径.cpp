/*
  输入一棵二叉树和一个整数，打印出二叉树节点值的和为输入整数的所有路径。
  二叉树的路径：从根节点开始往下一直到叶节点所经过的节点形成的一条路径。
*/

#include"predefines.h"
using std::pair;
using std::array;
using std::make_pair;
// 递归版本

void FindPaths(BinaryNode<int>* root, const int& expected,
	vector<int>& path, int cur_sum) {
	cur_sum += root->value;
	path.push_back(root->value);
	// 如果是叶节点且满足条件，打印
	if (cur_sum == expected && ((!root->left) && (!root->right))) {
		std::printf("A path found:\n");
		for (auto& p : path)
			std::printf("%d -> ", p);
		cout << "null" << endl;
	}
	if (root->left)
		FindPaths(root->left, expected, path, cur_sum);
	if (root->right)
		FindPaths(root->right, expected, path, cur_sum);
	// 返回父节点，在路径上删除当前节点
	path.pop_back();
}

void FindPaths(BinaryNode<int>* root, const int& expected) {
	if (!root)
		return;
	vector<int> path;
	int cur_sum = 0;
	FindPaths(root, expected, path, cur_sum);
}


// 非递归版本
void FindPaths_NonRecur(BinaryNode<int>* root, const int& expected) {
	int cur_sum = 0;
	const int LEFT = 0, RIGHT = 1;
	// 用 vector(2) 表示是否已访问过左/右子节点
	vector<pair<BinaryNode<int>*, vector<bool>>> path; 
	path.push_back({ root, { false,false } });
	cur_sum += root->value;
	while (!path.empty()) {
		auto cur = path.back();
		if (!cur.first->left && !cur.first->right) {
			if (cur_sum == expected) {
				std::printf("A path found:\n");
				for (auto& p : path)
					std::printf("%d -> ", p.first->value);
				cout << "null" << endl;
				cur_sum -= cur.first->value;
				path.pop_back();
			}
			else {
				cur_sum -= cur.first->value;
				path.pop_back();
			}
			continue;
		}
		if (cur.first->left && !cur.second[LEFT]) {
			path.back().second[LEFT] = true;  // 不能是cur.second[LEFT]=true, cur只是一个副本，更改不会生效
			path.push_back({ cur.first->left ,{ false,false } });  // 先设置back()的访问标志，再push_back新的值
			cur_sum += cur.first->left->value;
		}
		else if (cur.first->right && !cur.second[RIGHT]) {
			path.back().second[RIGHT] = true;
			path.push_back({ cur.first->right,{ false,false } });
			cur_sum += cur.first->right->value;
		}
		else {
			path.pop_back();
			cur_sum -= cur.first->value;
		}
	}

}

int main() {
	vector<int> tree{ 10,5,12,4,7 };
	BinaryNode<int>* root = new BinaryNode<int>;
	BuildBTree(&root, tree);
	FindPaths_NonRecur(root, 22);
	DestoryBTree(&root);
	return 0;
}