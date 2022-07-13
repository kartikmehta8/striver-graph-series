#include <bits/stdc++.h>

//Ctrl+Alt+F    To format the code
//Ctrl+B        To run the code
//Ctrl+/        To comment the lines completly
//Ctrl+Shift+/  To comment the required/selected lines only

using namespace std;

void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int, int>> adj[]) {
	vis[node] = 1;
	for (auto it: adj[node]) {
		if (!vis[it.first]) findTopoSort(it.first, vis, st, adj);
	}
	st.push(node);
}

void shortestPath(int source, int num_of_nodes, vector<pair<int, int>> adj[]) {
	int vis[num_of_nodes] = {0};
	stack<int> st;

	for (int i = 1; i <= num_of_nodes; i++) {
		if (!vis[i]) findTopoSort(i, vis, st, adj);
	}

	int dist[num_of_nodes];
	for (int i = 1; i <= num_of_nodes; i++) dist[i] = INT_MAX;
	dist[source] = 0;

	while (!st.empty()) {
		int node = st.top();
		st.pop();

		if (dist[node] != INT_MAX) {
			for (auto it: adj[node]) {
				if (dist[node] + it.second < dist[it.first]) {
					dist[it.first] = dist[node] + it.second;
				}
			}
		}
	}

	for (int i = 1; i <= num_of_nodes; i++) {
		(dist[i] == INT_MAX) ? cout << "INF " : cout << dist[i] << " ";
	}
}

int main() {

	// 6 7
	// 1 2 2
	// 1 5 1
	// 2 3 3
	// 5 3 2
	// 5 6 4
	// 6 4 1
	// 3 4 6
	// 1 4

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
		// adj[node_edge_2].push_back({node_edge_1, weight});
	}

	// for (int i = 1; i < num_of_nodes+1; i++) {
	// 	cout << "Nodes adjcent to Node " << i << " : ";
	// 	for (auto it: adj[i]) {
	// 		cout << it.first << "(" << it.second << ") ";
	// 	}

	// 	cout << "\n";
	// }

	int source, destination;
	cin >> source >> destination;

	shortestPath(source, num_of_nodes, adj);

	return 0;
}
