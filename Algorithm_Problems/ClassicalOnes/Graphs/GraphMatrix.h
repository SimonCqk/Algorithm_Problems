#pragma once
#include<vector>
#include<iostream>
#include<map>

using std::vector;
using std::map;

class Edge final
{
	friend class GraphMatrix;
public:
	explicit Edge(const size_t& start, const size_t& end, const double& value)
		:start_idx(start), end_idx(end), value(value) {}
	~Edge() = default;
private:
	size_t start_idx;
	size_t end_idx;
	double value;
};

class GraphMatrix
{
public:
	explicit GraphMatrix(const size_t& size);
	explicit GraphMatrix(const vector<Edge>& edges);
	~GraphMatrix();
	void showAll() const;
	size_t getSize() const;
	size_t getNumOfEdges() const;
	double getValue(const size_t& start, const size_t& end) const;

	void addEdge(const size_t& start, const size_t& end, const double& value);
	void addEdge(const Edge& edge);
	void removeEdge(const size_t& start, const size_t& end);
	void removeEdge(const Edge& edge);
private:
	vector<vector<double>> matrix;
	map<int, vector<int>> neighbor_table;
	size_t size;
	size_t number_of_edges;
};

