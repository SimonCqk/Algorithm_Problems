#include"graph.h"

using namespace std;

int main() {
	Graph<int> graph(5);
	graph.addEdge(0, 1, 2);
	graph.addEdge(0, 2, 3);
	graph.addEdge(0, 3, 1);
	graph.addEdge(1, 0, 2);
	graph.addEdge(1, 3, 4);
	graph.addEdge(2, 0, 3);
	graph.addEdge(2, 3, 1);
	graph.addEdge(2, 4, 1);
	graph.addEdge(3, 0, 1);
	graph.addEdge(3, 1, 4);
	graph.addEdge(3, 2, 1);
	graph.addEdge(3, 4, 3);
	graph.addEdge(4, 2, 1);
	graph.addEdge(4, 3, 3);
	graph.showAdjMatrix();
	graph.DFS();
	cout << endl;
	graph.BFS(0);
	cout << endl;
	//cout << "sum of minimum spanning tree is : " << graph.MiniSpanTree_Prim() << std::endl;
	graph.optmzed_SingleSourcePath();
	return 0;
}