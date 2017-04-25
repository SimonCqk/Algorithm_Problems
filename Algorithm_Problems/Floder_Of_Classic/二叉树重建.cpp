//Binary_Tree Reconstruction;
//Input the number of nodes, Preoder, Inoder;
//Output the Postorder formated

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int BTree_size,pos;

void Reconstruction(int left, int right,vector<int>& Pre,vector<int>& In,vector<int>& Post) {
	if (left >= right)return;
	int root = Pre[pos++];
	int mid = std::distance(In.begin(), find(In.begin(), In.end(), root));
	Reconstruction(left, mid, Pre, In, Post);
	Reconstruction(mid + 1, right,  Pre, In, Post);
	Post.push_back(root);
}

void Solve(vector<int>& Pre, vector<int>& In, vector<int>& Post) {
	pos = 0;
	auto Pre_size = Pre.size();
	Reconstruction(0, Pre_size, Pre, In, Post);
	for (int i = 0; i < BTree_size; ++i) {
		if (i)cout << ' ';
		cout << Post[i];
	}
	cout << endl;
}

int main() {
	int item;
	vector<int> Preorder, Inorder, Postorder;
	cin >> BTree_size;
	for (int i = 0; i < BTree_size; ++i) {
		cin >> item;
		Preorder.push_back(item);
	}
	for (int i = 0; i < BTree_size; ++i) {
		cin >> item;
		Inorder.push_back(item);
	}
	Solve(Preorder,Inorder,Postorder);
	return 0;
}