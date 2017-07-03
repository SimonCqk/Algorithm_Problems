/*
Balanced Binary Tree (Adelson-Velskii-Landis Tree)
Based on the Binary Search Tree
*/
// http://blog.csdn.net/xiajun07061225/article/details/8292505
#include<iostream>
#include<memory>
#include<vector>

using std::cin;
using std::cout;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;

template<class Type>
class TreeNode {
public:
	TreeNode():
		height(1),leftChild(nullptr),rightChild(nullptr){}
	Type data;
	size_t height;
	TreeNode* leftChild;
	TreeNode* rightChild;
};


template<class Type>
class AVLTree {
	using TNode = shared_ptr<TreeNode<Type>>;
	using TType = TreeNode<Type>;
public:
	AVLTree() :
		root(make_shared<TType>(new TType())) {}
	~AVLTree()=default;
	//创建二叉平衡树
	void createAVLTree(TNode node, const vector<Type>& data);
	//插入节点
	TNode insertNode(const Type& value);
	//删除特定值的节点
	TNode deleteNode(const Type& value);
	//搜索特定值的节点，并返回该节点
	TNode searchNode(const Type& value);
	//前序遍历输出树
	void preOrdered();
	//返回最大值的节点
	TNode maxNode();
	//返回最小值节点
	TNode minNode();
private:
	TNode root;  //根节点

	size_t getHeight();  //返回树的高度
	void setHeight();  //设置树的高度

	//旋转操作
	//单向右旋
	TNode singleRightRotate(TNode);
	//单向左旋
	TNode singleLeftRotate(TNode);
	//双向旋转：左右
	TNode doubleRightRotate(TNode);
	//双向旋转：右左
	TNode doubleLeftRotate(TNode);

};


template<class Type>
TNode AVLTree<Type>::insertNode(TNode node, const Type& value) 
{
	auto newNode = make_shared<TType>(new TType());
	newNode->data = value;
	if (!node->get()) {
		node = newNode;
		return node;
	}
	//插入的值与根节点的值一样
	if (node->data == value)
	{
		cout << "AVL树中已有相同的元素存在，插入节点失败 ." << std::endl;
		return node;
	}

	//插入的值小于节点的值，插入左子树中
	if (value < node->data)
	{
		(*node)->leftChild = insertNode(*(node)->leftChild, value);
	}
}