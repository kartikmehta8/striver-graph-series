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
	// 1 4 1
	// 2 5 5
	// 4 3 3
	// 3 2 4
	// 3 5 1
	// 1 5

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

	int source, destination;
	cin >> source >> destination;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(num_of_nodes+1, INT_MAX);

	dist[source] = 0;
	pq.push({0, source});

	while (!pq.empty()) {
		int distance = pq.top().first;
		int prev = pq.top().second;
		pq.pop();

		for (auto it: adj[prev]) {
			int next = it.first;
			int nextDist = it.second;

			if (dist[next] > dist[prev]+nextDist) {
				dist[next] = dist[prev]+nextDist;
				pq.push({dist[next], next});
			}
		}
	}

	for (int i = 1; i <= num_of_nodes; i++) cout << dist[i] << " ";

	cout << "\nShorted distance from " << source << " to " << destination << " is " << dist[destination]; 

	return 0;
}
