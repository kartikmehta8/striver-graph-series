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
		adj[node_edge_2].push_back(node_edge_1);
	}

	vector<int> bfs_result;
	vector<int> vis(num_of_nodes, 0);

	for (int i = 1; i <= num_of_nodes; i++) {
		if (!vis[i]) {
			queue<int> q;
			q.push(i);
			vis[i] = 1;

			while (!q.empty()) {
				int node = q.front();
				q.pop();
				bfs_result.push_back(node);

				for (auto it: adj[node]) {
					if (!vis[it]) {
						q.push(it);
						vis[it] = 1;
					}
				}
			}
		}
	}

	for (auto it: bfs_result) {
		cout << it << " ";
	}


	return 0;
}
