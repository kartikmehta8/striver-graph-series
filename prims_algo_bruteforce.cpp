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

	// 5 6
	// 1 2 2
	// 1 4 6
	// 4 2 8
	// 2 3 3
	// 2 5 5
	// 3 5 7

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

	// for (int i = 1; i < num_of_nodes+1; i++) {
	// 	cout << "Nodes adjcent to Node " << i << " : ";
	// 	for (auto it: adj[i]) {
	// 		cout << it.first << "(" << it.second << ") ";
	// 	}

	// 	cout << "\n";
	// }


	int parent[num_of_nodes+1], key[num_of_nodes+1];
	bool mstSet[num_of_nodes+1];

	for (int i = 1; i <= num_of_nodes; i++) {
		key[i] = INT_MAX;
		mstSet[i] = false;
		parent[i] = -1;
	}

	key[1] = 0;
	parent[1] = -1;

	for (int count = 0; count < num_of_nodes-1; count++) {
		int mini = INT_MAX, u;

		for (int v = 1; v <= num_of_nodes; v++) {
			if (mstSet[v] == false && key[v] < mini) {
				mini = key[v];
				u = v;
			}
		}

		mstSet[u] = true;

		for (auto it: adj[u]) {
			int v = it.first;
			int w = it.second;

			if (mstSet[v] == false && w < key[v]) {
				parent[v] = u;
				key[v] = w;
			}
		}
	}

	for (int i = 2; i <= num_of_nodes; i++) {
		cout << parent[i] << "-" << i << " \n";
	}

	return 0;
}
