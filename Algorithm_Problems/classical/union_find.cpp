#include<vector>
#include<memory>
#include<unordered_map>

template<typename T>
class DisjointNode {

	using NodePtr = std::shared_ptr<DisjointNode>;

public:
	DisjointNode(T&& val)
		:value_(std::forward<T>(val)), depth_(0), parent_(nullptr) {}

	void setParent(const NodePtr& p) {
		parent_.reset();
		parent_ = p;
	}

	NodePtr getParent() const {
		return parent_.lock();
	}

	T getValue() const {
		return value_;
	}

	size_t getDepth() const {
		return depth_;
	}

	void increaseDepth() {
		++depth_;
	}

private:
	std::weak_ptr<DisjointNode<T>> parent_;
	T value_;
	size_t depth_;
};

// 并查集具体实现
template<typename T>
class DisjointSet {

	using NodeMap = std::unordered_map<T, std::shared_ptr<DisjointNode<T>>>;
	using NodePtr = DisjointNode::NodePtr;

public:

	// 创建一个只含x的集合, x不应出现在其他任何一个集合中.
	void makeSet(const T& ele) {
		node_map_.clear();
		node_map_.insert({ ele,std::make_shared<T>(ele) });
	}

	// 将元素x所在的集合S(x), 和元素y所在的集合S(y)进行合并, 且S(x) != S(y).
	void setUnion(const int& x, const int& y) {
		int px = findSet(x); int py = findSet(y);
		if (px != py)
			path[py] = px;
	}

	NodePtr findSet(const NodePtr& ptr) {
		auto parent = ptr->getParent();
		std::vector<NodePtr> path;
		while (parent->getParent() != nullptr) {
			// 一直找到根节点为止
			path.push_back(parent);
			parent = parent->getParent();
		}

		for (auto&& each : path)
			each->setParent(parent);
		return parent;
	}

	// 查找元素x所在集合的代表.
	int findSet(const T& ele) {
		
	}

private:
	NodeMap node_map_;
};