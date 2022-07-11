#include <bits/stdc++.h>

//Ctrl+Alt+F    To format the code
//Ctrl+B        To run the code
//Ctrl+/        To comment the lines completly
//Ctrl+Shift+/  To comment the required/selected lines only

using namespace std;

void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
	vis[node] = 1;

	for (auto it: adj[node]) {
		if (!vis[it]) {
			findTopoSort(it, vis, st, adj);
		}
	}
	st.push(node);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int num_of_nodes, edges;
	cin >> num_of_nodes >> edges;

	// Declare the adjacent list
	vector<int> adj[num_of_nodes+1];

	for (int i = 0; i < edges; i++) {
		int node_edge_1, node_edge_2;
		cin >> node_edge_1 >> node_edge_2;

		adj[node_edge_1].push_back(node_edge_2);

		// If it is directed graph, we omit this line
		// adj[node_edge_2].push_back(node_edge_1);
	}

	vector<int> vis(num_of_nodes, 0);
	stack<int> st;

	for (int i = 1; i <= num_of_nodes; i++) {
		if (vis[i] == 0) findTopoSort(i , vis, st, adj);
	}

	vector<int> topo;

	while (!st.empty()) {
		topo.push_back(st.top());
		st.pop();
	}

	for (auto it: topo) {
		cout << it << " ";
	}

	return 0;
} 
