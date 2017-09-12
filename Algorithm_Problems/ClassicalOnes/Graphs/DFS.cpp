#include"GraphMatrix.h"
#include<stack>

using namespace std;

vector<int> path;  // 记录DFS经过的路径
stack<Edge> dfs_s;


void DFS_visit(Graph& graph, const int& index) {
	Edge &n = graph.getNode(index);
	dfs_s.push(n);
	path.push_back(index);
	n.setFlag(Flags::be_visiting);
	while (!dfs_s.empty()) {
		int next = dfs_s.top().getEnd(); // index of next node
		if (next != -1) {
			Edge &node = graph.getNode(next);
			if (node.getFlag() == Flags::unvisited) {
				node.setFlag(Flags::be_visiting);
				dfs_s.push(node);
				path.push_back(next);
			}
		}
		else {
			dfs_s.pop();
			n.setFlag(Flags::visited);
		}
	}
}

int main() {
	int num;
	cin >> num;
	Graph graph(num);
	int total_node = 0;
	for (int i = 0; i < num; ++i) {
		int neighbors;
		cin >> neighbors;
		total_node += neighbors;
		if (!neighbors) {
			graph.addNode(i, 0, 1);
		}
		else
			for (int j = 0; j < neighbors; ++j) {
				int end;
				cin >> end;
				graph.addNode(i, end-1, 1);
			}
	}
	//graph.showAll();
	for (int i = 0; i < total_node; ++i) {
		if (graph.getNode(i).getFlag() == Flags::unvisited)
			DFS_visit(graph, i);
	}

	for (const int& i : path)
		cout << i << " ";
	cout << endl;
	return 0;
}