#include <bits/stdc++.h>

//Ctrl+Alt+F    To format the code
//Ctrl+B        To run the code
//Ctrl+/        To comment the lines completly
//Ctrl+Shift+/  To comment the required/selected lines only

using namespace std;

void dfs(int node, int parent, vector<int> &vis, vector<int> &time, vector<int> &low, int &timer, vector<int> adj[]) {
	vis[node] = 1;
	time[node] = low[node] = timer++;

	for (auto it: adj[node]) {
		if (it == parent) continue;

		if (!vis[it]) {
			dfs(it, node, vis, time, low, timer, adj);
			low[node] = min(low[node], low[it]);

			if (low[it] > time[node]) cout << node << " " << it << "\n";
		} else {
			low[node] = min(low[node], time[it]);
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// 12 14
	// 1 2
	// 1 4
	// 4 3
	// 2 3
	// 4 5
	// 5 6
	// 6 7
	// 7 8
	// 8 9
	// 6 9
	// 8 10
	// 10 12
	// 10 11
	// 11 12

	int num_of_nodes, edges;
	cin >> num_of_nodes >> edges;

	vector<int> adj[num_of_nodes+1];

	for (int i = 0; i < edges; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> time(num_of_nodes+1, -1);
	vector<int> low(num_of_nodes+1, -1);
	vector<int> vis(num_of_nodes+1, 0);
	int timer = 1;

	for (int i = 1; i <= num_of_nodes; i++) {
		if (!vis[i]) dfs(i, -1, vis, time, low, timer, adj);
	}

	return 0;
}
