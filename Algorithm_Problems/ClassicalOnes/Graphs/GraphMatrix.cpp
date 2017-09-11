#include "GraphMatrix.h"
#include<cassert>
#include<algorithm>


GraphMatrix::GraphMatrix(const size_t & size)
{
	assert(size > 0);
	matrix.resize(size);
	for (auto &vec : matrix) {
		vec.resize(size, 0);
	}
}

GraphMatrix::GraphMatrix(const vector<Node>& nodes)
{
	int size = nodes.size();
	matrix.resize(size);
	for (auto &vec : matrix) {
		vec.resize(size, 0);
	}
	for (const Node& node : nodes) {
		assert(node.start_idx < size&&node.end_idx < size);
		matrix[node.start_idx][node.end_idx] = node.value;
	}
}

GraphMatrix::~GraphMatrix()
{
}

void GraphMatrix::showAll() const
{
	for (const auto &vec : matrix) {
		for (const auto &item : vec)
			std::cout << item << " ";
		std::cout << std::endl;
	}
}


size_t GraphMatrix::getNumOfNodes() const
{
	return this->nodes.size();
}

double GraphMatrix::getValue(const size_t & start, const size_t & end) const
{
	return matrix[start][end];
}

auto GraphMatrix::findNode(const size_t & start, const size_t & end) const
{
	for (auto beg = nodes.cbegin(), ed = nodes.cend(); beg != ed; ++beg) {
		if (beg->start_idx == start&&beg->end_idx == end)
			return beg;
	}
}

int GraphMatrix::getNodeDegree(const size_t & start) const
{
	int cnt = 0;
	for (const auto &node : nodes) {
		if (node.start_idx == start)
			++cnt;
	}
	return cnt;
}


void GraphMatrix::addNode(const size_t & start, const size_t & end, const double & value)
{
	matrix[start][end] = value;
	nodes.push_back(Node(start, end, value));
}

void GraphMatrix::addNode(const Node & node)
{
	matrix[node.start_idx][node.end_idx] = node.value;
	nodes.push_back(node);
}

void GraphMatrix::removeNode(const size_t & start, const size_t & end)
{
	matrix[start][end] = 0;
	nodes.erase(findNode(start, end));
}

void GraphMatrix::removeNode(const Node & node)
{
	matrix[node.start_idx][node.end_idx] = 0;
	nodes.erase(findNode(node.start_idx, node.end_idx));
}
