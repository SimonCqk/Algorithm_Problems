/*
Balanced Binary Tree (Adelson-Velskii-Landis Tree)
Based on the Binary Search Tree
*/
#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
#include<cassert>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::max;
using std::min;

template<typename Type>
class TreeNode {
public:
	TreeNode() :
		height(1), leftChild(nullptr), rightChild(nullptr) {}
	Type data;
	size_t height;
	shared_ptr<TreeNode> leftChild;
	shared_ptr<TreeNode> rightChild;
};

template<typename Type>
class AVLTree {
	using TNode = shared_ptr<TreeNode<Type>>;
	using TType = TreeNode<Type>;
public:
	AVLTree() :
		root(nullptr) {}
	~AVLTree() = default;
	//创建二叉平衡树
	void createAVLTree(const vector<Type>& data);
	//插入节点
	TNode insertNode(TNode node, const Type& value);
	//删除特定值的节点
	TNode deleteNode(TNode node, const Type& value);
	//搜索特定值的节点，并返回该节点
	TNode searchNode(TNode node, const Type& value);
	//前序遍历输出树
	void preOrdered(TNode node);
	//返回最大值的节点
	TNode maxNode(TNode node);
	//返回最小值节点
	TNode minNode(TNode node);
	TNode root;  //根节点
private:
	size_t getHeight(TNode node);  //返回树的高度
	void setHeight(TNode node, const size_t& newheight);  //设置树的高度

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

template<typename Type>
inline size_t AVLTree<Type>::getHeight(TNode node)
{
	return (node.get() == nullptr) ? 0 : node->height;
}

template<typename Type>
inline void AVLTree<Type>::setHeight(TNode node, const size_t& newheight)
{
	node->height = newheight;
}

//定义各种旋转修正平衡性操作
//左左不平衡，单-右旋转 : node - 失去平衡的最小树根节点
template<typename Type>
shared_ptr<TreeNode<Type>> AVLTree<Type>::singleRightRotate(TNode node)
{
	TNode xNode = node;
	TNode yNode = (*node).leftChild;
	(*xNode).leftChild = (*yNode).rightChild;  //更改原节点的左孩子
	(*yNode).rightChild = xNode;	//更改原节点左孩子的右孩子
	//更新高度
	xNode->height = max(getHeight((*xNode).leftChild), getHeight((*xNode).rightChild)) + 1;
	yNode->height = max(getHeight((*yNode).leftChild), getHeight((*yNode).rightChild)) + 1;

	//原节点的左孩子称为新子树的根节点
	return yNode;
}

//右右不平衡，单-左旋转
template<typename Type>
shared_ptr<TreeNode<Type>> AVLTree<Type>::singleLeftRotate(TNode node)
{
	TNode xNode = node;
	TNode yNode = (*node).rightChild;
	(*xNode).rightChild = (*yNode).leftChild;
	(*yNode).leftChild = xNode;

	//更新高度
	xNode->height = max(getHeight((*xNode).leftChild), getHeight((*xNode).rightChild)) + 1;
	yNode->height = max(getHeight((*yNode).leftChild), getHeight((*yNode).rightChild)) + 1;

	//原节点的左孩子称为新子树的根节点
	return yNode;
}

//双-右旋转
template<typename Type>
shared_ptr<TreeNode<Type>> AVLTree<Type>::doubleRightRotate(TNode node)
{
	//双旋转可以通过两次单旋转实现
	//先单左，再单右
	assert(node->leftChild.get() != nullptr);	//不能用编译期断言的static_assert
	//对左子树进行一次单-左旋转
	(*node).leftChild = singleLeftRotate((*node).leftChild);
	//对新产生的树进行一次单-右旋转
	return singleRightRotate(node);
}

//双-左旋转
template<typename Type>
shared_ptr<TreeNode<Type>> AVLTree<Type>::doubleLeftRotate(TNode node)
{
	//双旋转可以通过两次单旋转实现
	//先单右，再单左
	assert((*node).rightChild.get() != nullptr);
	//对右子树进行一次单-右旋转
	(*node).rightChild = singleRightRotate((*node).rightChild);
	//对新产生的树进行一次单-左旋转
	return singleLeftRotate(node);
}

template<typename Type>
shared_ptr<TreeNode<Type>> AVLTree<Type>::insertNode(TNode node, const Type& value)
{
	TNode newNode = make_shared<TType>(TType());
	newNode->data = value;
	if (!node.get()) {
		node = newNode;
		return node;
	}
	//插入的值与根节点的值一样
	if (node->data == value)
	{
		cout << "AVL树中已有相同的元素存在，插入节点失败 ." << endl;
		return node;
	}

	//插入的值小于节点的值，插入左子树中
	if (value < node->data)
	{
		(*node).leftChild = insertNode((*node).leftChild, value);
		//判断是否平衡
		if (getHeight((*node).leftChild) - getHeight((*node).rightChild) > 1)
		{
			//分两种情况旋转
			//插入点是左子节点的左子树，单-右旋转
			if (value < (*node).leftChild->data)
				node = singleRightRotate(node);
			else
				//插入点是左子节点的右子树，双-右旋转
				node = doubleRightRotate(node);
		}
	}
	//插入的值大于节点的值，插入右子树
	if (value > node->data)
	{
		(*node).rightChild = insertNode((*node).rightChild, value);
		//判断是否平衡
		if (getHeight((*node).rightChild) - getHeight((*node).leftChild) > 1)
		{
			//同样两种情况
			//插入点是右子节点的右子树，单-左旋
			if (value > (*node).rightChild->data)
				node = singleLeftRotate(node);
			else
				//插入点是右子节点的左子树，双-左旋
				node = doubleLeftRotate(node);
		}
	}
	//更新节点的高度
	setHeight(node, max(getHeight((*node).leftChild), getHeight((*node).rightChild)) + 1);
	return node;
}

template<typename Type>
void AVLTree<Type>::createAVLTree(const vector<Type>& data)
{
	if (root.get())
	{
		cout << "The AVL Tree has been created ." << endl;
		return;
	}
	if (data.empty())
	{
		root = nullptr;
		return;
	}
	for (auto& i : data)
	{
		root = insertNode(root, i);
	}
}

template<typename Type>
shared_ptr<TreeNode<Type>> AVLTree<Type>::searchNode(TNode node, const Type& value)
{
	if (!node.get())
	{
		return nullptr;
	}
	if (node->data == value)
	{
		return node;
	}
	else if (node->data < value)
	{
		return searchNode((*node).leftChild, value);
	}
	else
	{
		return searchNode((*node).rightChild, value);
	}
}

template<typename Type>
shared_ptr<TreeNode<Type>> AVLTree<Type>::minNode(TNode node)
{
	if (!root.get())
	{
		return nullptr;
	}
	TNode temp = node;
	while ((*temp).leftChild)
	{
		temp = (*temp).leftChild;
	}
	return temp;
}

template<typename Type>
shared_ptr<TreeNode<Type>> AVLTree<Type>::maxNode(TNode node)
{
	if (!root.get())
	{
		return nullptr;
	}
	TNode temp = node;
	while ((*temp).rightChild)
	{
		temp = (*temp).rightChild;
	}
	return temp;
}

template<typename Type>
void AVLTree<Type>::preOrdered(TNode node)
{
	if (!root.get())
	{
		cout << "Empty Tree ." << endl;
		return;
	}
	if (!node.get())cout << " Null ";
	else
	{
		cout << node->data << " - ";
		preOrdered((*node).leftChild);
		preOrdered((*node).rightChild);
	}
}

template<typename Type>
shared_ptr<TreeNode<Type>> AVLTree<Type>::deleteNode(TNode node, const Type& value)
{
	if (!node.get())
	{
		cout << "The Tree is empty...delete failed..." << std::endl;
		return node;
	}
	TNode searched = searchNode(node, value);
	//没有找到相应节点，删除失败
	if (!searched.get())
	{
		cout << "Can not find the node to delete ." << std::endl;
		return node;
	}
	//找到需要删除的节点
	//即当前子树根节点
	if (node->data == value)
	{
		//左右子树皆非空
		if ((*node).leftChild && (*node).rightChild)
		{
			//在高度更大的子树上进行删除操作
			if (getHeight((*node).leftChild) > getHeight((*node).rightChild))
			{
				//左子树高度更大，删除左子树中元素值最大的点，同时把它的值赋给根节点
				node->data = maxNode((*node).leftChild)->data;
				(*node).leftChild = deleteNode((*node).leftChild, node->data);
			}
			else
			{
				//删除右子树中值最小的节点，同时把它的值赋给根节点
				node->data = minNode((*node).rightChild)->data;
				(*node).rightChild = deleteNode((*node).rightChild, node->data);
			}
		}
		else
		{
			//左右子树中有一个不为空，直接用子节点替换之
			node = ((*node).leftChild ? (*node).leftChild : (*node).rightChild);
		}
	}
	else if (value < node->data)	//要删除的节点在左子树
	{
		//在左子树中递归删除
		(*node).leftChild = deleteNode((*node).leftChild, value);
		//判断是否仍然满足平衡条件
		if (getHeight((*node).rightChild) - getHeight((*node).leftChild) > 1)
		{
			if (getHeight((*node).rightChild->leftChild) - getHeight((*node).rightChild->rightChild))
			{
				//双-左旋转
				node = doubleLeftRotate(node);
			}
			else
				node = singleLeftRotate(node);
		}
		else
		{
			//满足平衡条件
			node->height = max(getHeight((*node).leftChild), getHeight((*node).rightChild)) + 1;
		}
	}
	else  //需要删除的节点在右子树
	{
		(*node).rightChild = deleteNode((*node).rightChild, value);
		//判断是否仍然满足平衡条件
		if (getHeight((*node).leftChild) - getHeight((*node).rightChild) > 1)
		{
			if (getHeight((*node).leftChild->rightChild) - getHeight((*node).leftChild->leftChild))
			{
				//双-右旋转
				node = doubleRightRotate(node);
			}
			else
				node = singleRightRotate(node);
		}
		else
		{
			//满足平衡条件
			node->height = max(getHeight((*node).leftChild), getHeight((*node).rightChild)) + 1;
		}
	}

	return node;
}


int main()
{
	vector<int> datas = { 2,67,5,3,22,112,78,54,4};
	AVLTree<int> TREE;
	TREE.createAVLTree(datas);
	cout << "先序遍历结果如下 ." << endl;
	TREE.preOrdered(TREE.root);
	cout << "树中最大元素/最小元素" << endl;
	cout << TREE.maxNode(TREE.root)->data << " / " << TREE.minNode(TREE.root)->data << endl;
	cout << "删除值为4的节点后，先序遍历结果 ." << endl;
	TREE.root=TREE.deleteNode(TREE.root, 4);
	TREE.preOrdered(TREE.root);
	cout << "查找值为112的结点" << endl;
	TreeNode<int> *node = &(*(TREE.searchNode(TREE.root, 112)));
	if (node)
	{
		cout << "Search the node successfully ." << endl;
	}
	else
		cout << "Search failed ." << endl;
	return 0;
}