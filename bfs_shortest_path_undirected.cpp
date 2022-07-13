#include <bits/stdc++.h>

//Ctrl+Alt+F    To format the code
//Ctrl+B        To run the code
//Ctrl+/        To comment the lines completly
//Ctrl+Shift+/  To comment the required/selected lines only

using namespace std;

int main() {

	// 9 11
	// 1 2 1
	// 1 4 1
	// 2 4 1
	// 4 5 1
	// 5 6 1
	// 6 7 1
	// 3 7 1
	// 7 8 1
	// 7 9 1
	// 8 9 1
	// 2 3 1
	// 1 7

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

	// for (int i = 1; i < num_of_nodes+1; i++) {
	// 	cout << "Nodes adjcent to Node " << i << " : ";
	// 	for (auto it: adj[i]) {
	// 		cout << it.first << "(" << it.second << ") ";
	// 	}

	// 	cout << "\n";
	// }

	int source, destination, dist[num_of_nodes+1];
	cin >> source >> destination;

	for (int i = 1; i <= num_of_nodes; i++) dist[i] = INT_MAX;

	queue<int> q;

	dist[source] = 0;
	q.push(source);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (auto it: adj[node]) {
			if (dist[node]+1 < dist[it.first]) {
				dist[it.first] = dist[node]+1;
				q.push(it.first);
			}
		}
	}

	for (int i = 1; i <= num_of_nodes; i++) cout << dist[i] << " ";

	cout << "\nShorted distance from " << source << " to " << destination << " is " << dist[destination]; 

	return 0;
}
