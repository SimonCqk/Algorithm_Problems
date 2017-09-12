#pragma once
#include<vector>
#include<iostream>

using std::vector;

enum class Flags
{
	unvisited,
	be_visiting,
	visited
};
class Edge final
{
	friend class Graph;
public:
	explicit Edge(const size_t& start, const size_t& end=0, const double& value=0)
		:start_idx(start), end_idx(end), value(value) {}
	Flags getFlag() const { return flag; }
	void setFlag(const Flags& f) { flag = f; }
	size_t getEnd() const { return end_idx; }
	size_t getValue() const { return value; }
	~Edge() = default;
private:
	size_t start_idx;
	size_t end_idx;
	double value;
	Flags flag;
};

class Graph
{
public:
	Graph():
		num_edges(0){}
	explicit Graph(const size_t& size);
	~Graph()=default;
	void showAdjMatrix() const;
	vector<vector<int>> getAdjMartix() const;
	size_t getNumOfNodes() const;
	size_t getNumOfEdges() const;
	size_t getDegreeIn(const size_t& vertex_idx) const;
	size_t getDegreeOut(const size_t& vertex_idx) const;
	size_t getDegree(const size_t& vertex_idx) const;

	auto findEdge(const size_t& vertex_idx, const size_t& end) const; // return iterator points to the specific edge.

	void addEdge(const size_t& vertex_idx, const size_t& end, const double& value);
	void addEdge(const Edge& edge);
	void removeEdge(const size_t& vertex_idx, const size_t& end);
	void removeEdge(const Edge& edge);

	void DFS() const;
private:
	vector<vector<Edge>> vertexs;
	size_t num_edges;
	void DFS_visit();
};

