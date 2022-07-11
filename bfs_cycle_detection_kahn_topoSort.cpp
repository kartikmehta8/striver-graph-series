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
	vector<int> adj[num_of_nodes+1];

	for (int i = 0; i < edges; i++) {
		int node_edge_1, node_edge_2;
		cin >> node_edge_1 >> node_edge_2;

		adj[node_edge_1].push_back(node_edge_2);

		// If it is directed graph, we omit this line
		// adj[node_edge_2].push_back(node_edge_1);
	}

	queue<int> q;
	vector<int> indegree(num_of_nodes, 0);

	// Indegree calculation
	for (int i = 1; i <= num_of_nodes; i++) {
		for (auto it: adj[i]) {
			indegree[it]++;
		}
	}

	for (int i = 1; i <= num_of_nodes; i++) {
		if (indegree[i] == 0) q.push(i);
	}

	int cnt = 0;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cnt++;

		for (auto it: adj[node]) {
			indegree[it]--;

			if (indegree[it] == 0) q.push(it); 
		}
	}

	if (cnt == num_of_nodes) cout << "NO CYCLE\n";
	else cout << "CYCLE\n";

	return 0;
} 
