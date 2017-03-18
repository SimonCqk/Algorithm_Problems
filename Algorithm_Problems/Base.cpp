//Binary Search Tree
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

//define the Binary Search Tree class 
class BSearch_Tree {
public:
	int key;
	BSearch_Tree *left;
	BSearch_Tree *right;
	BSearch_Tree *parent;
	BSearch_Tree():left(nullptr),right(nullptr),parent(nullptr){}
	//¿½±´¹¹Ôìº¯Êý
	BSearch_Tree(const BSearch_Tree& T);
	BSearch_Tree& operator=(const BSearch_Tree& T);
	~BSearch_Tree();
};

BSearch_Tree::BSearch_Tree(const BSearch_Tree& T) {
	key = T.key;
	if(left==nullptr){ left = new BSearch_Tree(); *left = *T.left;}
	else *left = *T.left;;
	if (right == nullptr) { right = new BSearch_Tree(); *right = *T.right; }
	else *right = *T.right;
	if (parent == nullptr) { parent = new BSearch_Tree(); *parent = *T.parent; }
	else *parent = *T.parent;
}
BSearch_Tree& BSearch_Tree::operator=(const BSearch_Tree& T) {
	key = T.key;
	if (left == nullptr) { left = new BSearch_Tree(); *left = *T.left; }
	else *left = *T.left;;
	if (right == nullptr) { right = new BSearch_Tree(); *right = *T.right; }
	else *right = *T.right;
	if (parent == nullptr) { parent = new BSearch_Tree(); *parent = *T.parent; }
	else *parent = *T.parent;
	return *this;
}
BSearch_Tree::~BSearch_Tree() {
	if (!left) { delete left; left = nullptr; }
	if (!right) { delete right; right = nullptr; }
	if (!parent) { delete parent; parent = nullptr; }
}

//The operations of BSearch_Tree 
//Include : Insert the node , search the node , delete the node , print the tree 
void Insert_Node(BSearch_Tree* *T, int key) {
	BSearch_Tree** x = T;
	BSearch_Tree *y = nullptr, *z = new BSearch_Tree();
	z->key = key;
	if (*x == nullptr) {
		*T =z;
		cout << (*T)->key;
		return;
	}
	while (*x !=nullptr ) {
		y = *x;   //set y as parent
		*x = (z->key < (*x)->key) ? (*x)->left : (*x)->right;
	}
		z->parent = y;
		if (z->key < y->key) {
			 y->left = z;
		}
		else {
			y->right = z;
		}
	
}

void Print_Tree(const BSearch_Tree *T) {
		if (!T) return; 
		cout << T->key << ' ';
		Print_Tree(T->left);
		Print_Tree(T->right);
}

int main() {
	cout << "Input the number of cmds \n"
		 << "Formatted as : \"Insert \'key\' \"\n or            \"Search \'key\' \"\n or"
		 <<"            \"Delete \'key\' \"\n or"
		 <<"            \"Print\" "
		 << endl;
	BSearch_Tree* TREE=nullptr;
	int node_nums, key;
	string cmd;
	cin >> node_nums;
	for (int i = 0; i < node_nums; ++i) {
		cin >> cmd;
		if (cmd == "Insert") {
			cin >> key;
			Insert_Node(&TREE, key);
		}
		else if (cmd == "Print") {
			cout << "Printed by inordered :\n";
			Print_Tree(TREE);
		}
	}
	return 0;
}

