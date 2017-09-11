#pragma once
#include<vector>
#include<iostream>
#include<map>

using std::vector;
using std::map;

class Node final
{
	friend class GraphMatrix;
public:
	explicit Node(const size_t& start, const size_t& end, const double& value)
		:start_idx(start), end_idx(end), value(value) {}
	~Node() = default;
private:
	size_t start_idx;
	size_t end_idx;
	double value;
};

class GraphMatrix
{
public:
	explicit GraphMatrix(const size_t& size);
	explicit GraphMatrix(const vector<Node>& nodes);
	~GraphMatrix();
	void showAll() const;
	size_t getNumOfNodes() const;
	double getValue(const size_t& start, const size_t& end) const;
	auto findNode(const size_t& start, const size_t& end) const;
	int getNodeDegree(const size_t& start) const;

	void addNode(const size_t& start, const size_t& end, const double& value);
	void addNode(const Node& edge);
	void removeNode(const size_t& start, const size_t& end);
	void removeNode(const Node& node);
private:
	vector<vector<double>> matrix;
	vector<Node> nodes;
};

