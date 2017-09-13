#pragma once
#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include<vector>
#include<iostream>
#include<algorithm>
#include<cassert>
#include<stack>

using std::vector;
using std::stack;
using std::cin;
using std::cout;
using std::endl;

enum class Flags
{
	unvisited,
	be_visiting,
	visited,
	finish_visit
};

template<typename Type>
class Edge final
{
	template<typename Type>
	friend class Graph;

public:
	explicit Edge(const size_t& start, const size_t& end = 0, const Type& value = Type())
		:start_idx(start), end_idx(end), value(value) {}
	size_t getEnd() const { return end_idx; }
	size_t getValue() const { return value; }
	~Edge() = default;
private:
	size_t start_idx;
	size_t end_idx;
	Type value;
};

template<typename Type>
class Graph
{
	using Node = vector<Edge<Type>>;
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

	void addEdge(const size_t& vertex_idx, const size_t& end, const Type& value);
	void removeEdge(const size_t& vertex_idx, const size_t& end);

	void DFS();
private:
	vector<Node> vertexs;
	vector<Flags> flags; // corresponding to the states of vertexs.
	size_t num_edges;
	void DFS_visit(const int& idx);
	int next(Node& node);
};

template<typename Type>
inline Graph<Type>::Graph(const size_t & size)
	:num_edges(0)
{
	assert(size > 0);
	vertexs.resize(size);
	flags.resize(size, Flags::unvisited);
}

template<typename Type>
inline void Graph<Type>::showAdjMatrix() const
{
	vector<vector<int>> matrix = getAdjMatrix();
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
	vector<vector<int>> matrix(size, vector<int>(size, 0));
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
	assert(vertex_idx >= 0 && vertex_idx < vertexs.size());
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
	assert(vertex_idx >= 0 && end >= 0);
	auto beg = vertexs[vertex_idx].begin(), ed = vertexs[vertex_idx].end();
	for (; beg != ed; ++beg) {
		if (beg->end_idx == end)
			return beg;
	}
	return ed;
}

template<typename Type>
inline void Graph<Type>::addEdge(const size_t & vertex_idx, const size_t & end, const Type & value)
{
	assert(vertex_idx >= 0 && end >= 0 && vertex_idx != end);
	if (vertex_idx > vertexs.size() || end > vertexs.size()) {
		vertexs.resize(max(vertex_idx, end) + 1);
		for (size_t i = 0; i < vertex_idx - vertexs.size(); ++i)
			flags.push_back(Flags::unvisited);
	}
	if (vertexs[vertex_idx].size() != 0 && value != vertexs[vertex_idx][0].value) {
		cout << "Invalid Input value." << endl;
		exit(0);
	}
	vertexs[vertex_idx].push_back(Edge<Type>(vertex_idx, end, value));
	++num_edges;
}

template<typename Type>
inline void Graph<Type>::removeEdge(const size_t & vertex_idx, const size_t & end)
{
	assert(vertex_idx < vertexs.size() && end < vertexs.size());
	auto candi = findEdge(vertex_idx, end);
	if (candi != vertexs[vertex_idx])
		vertexs[vertex_idx].erase(candi);
}

template<typename Type>
inline void Graph<Type>::DFS()
{
	cout << "Path is [always start from root index-0] : 0 ";
	int size = vertexs.size();
	for (int i = 0; i < size; ++i) {
		if (flags[i] == Flags::unvisited)
			DFS_visit(i);
	}
	cout << endl;
}

template<typename Type>
inline void Graph<Type>::DFS_visit(const int& idx)
{
	stack<Node> stack;
	stack.push(vertexs[idx]);
	flags[idx] = Flags::be_visiting;
	while (!stack.empty()) {
		Node& node = stack.top();
		int next_vert = next(node);
		if (next_vert != -1) {
			if (flags[next_vert] == Flags::unvisited) {
				flags[next_vert] = Flags::be_visiting;
				stack.push(vertexs[next_vert]);
				cout << next_vert << " ";
			}
		}
		else {
			stack.pop();
			flags[] = Flags::visited;
		}

	}
}

template<typename Type>
inline int Graph<Type>::next(Node& node)
{
	for (auto& i : node) {
		if (i.flag == Flags::unvisited) {
			i.flag = Flags::finish_visit;
			return i.end_idx;
		}
	}
	return -1;
}
