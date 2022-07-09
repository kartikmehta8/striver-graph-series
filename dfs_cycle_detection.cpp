#include <bits/stdc++.h>

//Ctrl+Alt+F    To format the code
//Ctrl+B        To run the code
//Ctrl+/        To comment the lines completly
//Ctrl+Shift+/  To comment the required/selected lines only

using namespace std;

bool checkForCycle(int node, int parent, vector<int>& vis, vector<int> adj[]) {
	vis[node] = 1;
	for (auto it: adj[node]) {
		if (!vis[it]) {
			if (checkForCycle(it, node, vis, adj)) return true;
		} else if (it != parent) return true;
	}

	return false;
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
		adj[node_edge_2].push_back(node_edge_1);
	}

	vector<int> dfs_result;
	vector<int> vis(num_of_nodes, 0);
	int cycle = 0;

	for (int i = 1; i <= num_of_nodes; i++) {
		if (!vis[i]) {
			if (checkForCycle(i, -1, vis, adj)) cycle = 1;
		}
	}

	if (cycle) cout << "There is a cycle!\n";
	else cout << "There is no cycle!\n";


	return 0;
}
