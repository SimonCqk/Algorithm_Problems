#include"GraphMatrix.h"

using namespace std;

int main() {
	Graph<int> graph(6);
	graph.addEdge(0,1, 1);
	graph.addEdge(1, 2, 1);
	graph.addEdge(2, 4, 1);
	graph.addEdge(1, 2, 1);
	graph.addEdge(1, 3, 1);
	graph.addEdge(3, 5, 1);
	graph.addEdge(4, 5, 1);
	graph.addEdge(5, 0, 1);
	graph.showAdjMatrix();
	graph.DFS();
	return 0;
}