#include <bits/stdc++.h>

//Ctrl+Alt+F    To format the code
//Ctrl+B        To run the code
//Ctrl+/        To comment the lines completly
//Ctrl+Shift+/  To comment the required/selected lines only

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int num_of_nodes, edges;
	cin >> num_of_nodes >> edges;

	// Declare the adjacent matrix
	int adj[num_of_nodes+1][num_of_nodes+1];

	// Initialization with 0 values
	for (int i = 0; i < num_of_nodes; i++) {
		for (int j = 0; j < num_of_nodes; j++) {
			adj[i][j] = 0;
		}
	}

	for (int i = 0; i < edges; i++) {
		int node_edge_1, node_edge_2;
		cin >> node_edge_1 >> node_edge_2;

		adj[node_edge_1][node_edge_2] = 1;
		adj[node_edge_2][node_edge_1] = 1;
	}

	for (int i = 0; i < num_of_nodes; i++) {
		for (int j = 0; j < num_of_nodes; j++) {
			cout << adj[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
