#pragma once
#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include<vector>
#include<iostream>
#include<algorithm>
#include<cassert>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

enum class Flags
{
	unvisited,
	be_visiting,
	visited
};

template<typename Type>
class Edge final
{
	friend class Graph;
public:
	explicit Edge(const size_t& start, const size_t& end = 0, const Type& value = Type())
		:start_idx(start), end_idx(end), value(value) {}
	Flags getFlag() const { return flag; }
	void setFlag(const Flags& f) { flag = f; }
	size_t getEnd() const { return end_idx; }
	size_t getValue() const { return value; }
	~Edge() = default;
private:
	size_t start_idx;
	size_t end_idx;
	Type value;
	Flags flag;
};

template<typename Type>
class Graph
{
public:
	Graph() :
		num_edges(0) {}
	explicit Graph(const size_t& size);
	~Graph() = default;
	void showAdjMatrix() const;
	vector<vector<int>> getAdjMatrix() const;
	size_t getNumOfNodes() const;
	size_t getNumOfEdges() const;
	size_t getDegreeIn(const size_t& vertex_idx) const;
	size_t getDegreeOut(const size_t& vertex_idx) const;
	size_t getDegree(const size_t& vertex_idx) const;
	Type getVertexValue(const size_t& vertex_idx) const;

	// return iterator points to the specific edge.
	decltype(auto) findEdge(const size_t& vertex_idx, const size_t& end) const; 

	void addEdge(const size_t& vertex_idx, const size_t& end, const double& value);
	void addEdge(const size_t& vertex_idx, const Edge& edge);
	void removeEdge(const size_t& vertex_idx, const size_t& end);

	void DFS() const;
private:
	vector<vector<Edge<Type>>> vertexs;
	size_t num_edges;
	void DFS_visit();
};

template<typename Type>
inline Graph<Type>::Graph(const size_t & size)
	:num_edges(0)
{
	assert(size > 0);
	vertexs.resize(size);
}

template<typename Type>
inline void Graph<Type>::showAdjMatrix() const
{
	vector<vector<int>> matrix= getAdjMatrix();
	for (const auto& i : matrix) {
		for (const auto& j : i)
			cout << j << " ";
		cout << endl;
	}
}

template<typename Type>
inline vector<vector<int>> Graph<Type>::getAdjMatrix() const
{
	int size = vertexs.size();
	vector<vector<int>> matrix(size, vector<int>(size,0));
	int i = 0;
	for (const auto& vertex : vertexs) {
		for (const auto& item : vertex) {
			matrix[i][item.end_idx] = item.value;
		}
		++i;
	}
	return matrix;
}

template<typename Type>
inline size_t Graph<Type>::getNumOfNodes() const
{
	return vertexs.size();
}

template<typename Type>
inline size_t Graph<Type>::getNumOfEdges() const
{
	return num_edges;
}

template<typename Type>
inline size_t Graph<Type>::getDegreeIn(const size_t & vertex_idx) const
{
	int degree_in = 0;
	int size = vertexs.size();
	for (int i = 0; i < size; ++i) {
		if (i == vertex_idx)
			continue;
		for (const auto& item : vertexs[i]) {
			if (item.end_idx == vertex_idx)
				++degree_in;
		}
	}
	return degree_in;
}

template<typename Type>
inline size_t Graph<Type>::getDegreeOut(const size_t & vertex_idx) const
{
	assert(vertex_idx > 0 && vertex_idx < vertexs.size());
	return vertexs[vertex_idx].size();
}

template<typename Type>
inline size_t Graph<Type>::getDegree(const size_t & vertex_idx) const
{
	return getDegreeIn(vertex_idx) + getDegreeOut(vertex_idx);
}

template<typename Type>
inline Type Graph<Type>::getVertexValue(const size_t & vertex_idx) const
{
	if (!vertexs[vertex_idx].size()) {
		cout << "No Such Vertex." << endl;
		exit();
	}
	return vertexs[vertex_idx][0].value;
}

#endif // !GRAPH_MATRIX_H

template<typename Type>
inline decltype(auto) Graph<Type>::findEdge(const size_t & vertex_idx, const size_t & end) const
{
	assert(vertex_idx > 0 && end > 0);
	if (vertex_idx > vertexs.size())
		vertexs.resize(vertex_idx + 1);
	auto beg = vertexs[vertex_idx].begin(), ed = vertexs[vertex_idx].end();
	for (; beg != ed; ++beg) {
		if (beg->end_idx == end)
			return beg;
	}
	return ed;
}

template<typename Type>
inline void Graph<Type>::addEdge(const size_t & vertex_idx, const size_t & end, const double & value)
{
	assert(vertex_idx > 0 && end > 0);
	if (vertex_idx > vertexs.size() || end > vertexs.size())
		vertexs.resize(max(vertex_idx,end) + 1);
	if (vertexs[vertex_idx].size() != 0 && value != vertexs[vertex_idx][0].value) {
		cout << "Invalid Input value." << endl;
		exit();
	}
	vertexs[vertex_idx].push_back(Edge(vertex_idx, end, value));
	++num_edges;
}

template<typename Type>
inline void Graph<Type>::addEdge(const size_t & vertex_idx, const Edge<Type> & edge)
{
	if (vertex_idx != edge.start_idx) {
		cout << "Invalid Edge." << endl;
		return;
	}
	if (vertexs[vertex_idx].size() != 0 && edge.value != vertexs[vertex_idx][0].value) {
		cout << "Invalid Input value." << endl;
		exit();
	}
	if (vertex_idx > vertexs.size())
		vertexs.resize(vertex_idx + 1);
	vertexs[vertex_idx].push_back(edge);
	++num_edges;
}

template<typename Type>
inline void Graph<Type>::removeEdge(const size_t & vertex_idx, const size_t & end)
{
	assert(vertex_idx < vertexs.size() && end < vertexs.size());
	auto candi = findEdge(vertex_idx, end);
	if(candi!=vertexs[vertex_idx])
		vertexs[vertex_idx].erase(candi);
}
