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

	// Declare the adjacent list
	vector<pair<int, int>> adj[num_of_nodes+1];

	for (int i = 0; i < edges; i++) {
		int node_edge_1, node_edge_2, weight;
		cin >> node_edge_1 >> node_edge_2 >> weight;

		adj[node_edge_1].push_back({node_edge_2, weight});

		// If it is directed graph, we omit this line
		adj[node_edge_2].push_back({node_edge_1, weight});
	}

	for (int i = 1; i < num_of_nodes+1; i++) {
		cout << "Nodes adjcent to Node " << i << " : ";
		for (auto it: adj[i]) {
			cout << it.first << "(" << it.second << ") ";
		}

		cout << "\n";
	}

	return 0;
}
