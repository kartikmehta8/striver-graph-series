#include <bits/stdc++.h>

//Ctrl+Alt+F    To format the code
//Ctrl+B        To run the code
//Ctrl+/        To comment the lines completly
//Ctrl+Shift+/  To comment the required/selected lines only

using namespace std;

bool bipartite(int node, vector<int> adj[], int color[]) {

	if (color[node] == -1) color[node] = 1;

	for (auto it: adj[node]) {
		if (color[it] == -1) {
			color[it] = 1 - color[node];

			if (!bipartite(it, adj, color)) return false;
		} else if (color[it] == color[node]) return false;
	}
	return true;
}

bool checkBipartiteDFS(vector<int> adj[], int num_of_nodes) {
	int color[num_of_nodes+1];
	memset(color, -1, sizeof(color));

	for (int i = 1; i <= num_of_nodes; i++) {
		if (color[i] == -1) {
			if (!bipartite(i, adj, color)) return false;
		}
	}
	return true;
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

	if (checkBipartiteDFS(adj, num_of_nodes)) cout << "This is a Bipartite Graph!\n";
	else cout << "This is not a Bipartite Graph!\n";


	return 0;
}
