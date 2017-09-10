#include "GraphMatrix.h"
#include<cassert>


GraphMatrix::GraphMatrix(const size_t & size)
	:size(size),number_of_edges(0)
{
	assert(size > 0);
	matrix.resize(size);
	for (auto &vec : matrix) {
		vec.resize(size, 0);
	}
}

GraphMatrix::GraphMatrix(const vector<Edge>& edges)
{
	int size = edges.size();
	matrix.resize(size);
	for (auto &vec : matrix) {
		vec.resize(size, 0);
	}
	this->size = size;
	this->number_of_edges = size;
	for (const Edge& edge : edges) {
		assert(edge.start_idx < size&&edge.end_idx < size);
		matrix[edge.start_idx][edge.end_idx] = edge.value;
	}
}

GraphMatrix::~GraphMatrix()
{
}

vector<double> & GraphMatrix::operator[](const int & idx)
{
	return matrix[idx];
}

void GraphMatrix::showAll() const
{
	for (auto &vec : matrix) {
		for (auto &item : vec)
			std::cout << item<<" ";
		std::cout << std::endl;
	}
}

size_t GraphMatrix::getSize() const
{
	return this->size;
}

size_t GraphMatrix::getNumOfEdges() const
{
	return this->number_of_edges;
}

double GraphMatrix::getValue(const size_t & start, const size_t & end) const
{
	return matrix[start][end];
}

double GraphMatrix::getValue(const Edge & edge) const
{
	return matrix[edge.start_idx][edge.end_idx];
}

void GraphMatrix::addEdge(const size_t & start, const size_t & end, const double & value)
{
	matrix[start][end] = value;
	++number_of_edges;
}

void GraphMatrix::addEdge(const Edge & edge)
{
	matrix[edge.start_idx][edge.end_idx] = edge.value;
	++number_of_edges;
}

void GraphMatrix::removeEdge(const size_t & start, const size_t & end)
{
	matrix[start][end] = 0;
	--number_of_edges;
}

void GraphMatrix::removeEdge(const Edge & edge)
{
	matrix[edge.start_idx][edge.end_idx] = 0;
	--number_of_edges;
}
