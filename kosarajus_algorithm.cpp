#include <bits/stdc++.h>

//Ctrl+Alt+F    To format the code
//Ctrl+B        To run the code
//Ctrl+/        To comment the lines completly
//Ctrl+Shift+/  To comment the required/selected lines only

using namespace std;

void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
	vis[node] = 1;
	for (auto it: adj[node]) {
		if (!vis[it]) dfs(it, st, vis, adj);
	}

	st.push(node);
}

void revDFS(int node, vector<int> &vis, vector<int> transpose[]) {
	cout << node << " ";
	vis[node] = 1;

	for (auto it: transpose[node]) {
		if (!vis[it]) revDFS(it, vis, transpose);
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// 5 5
	// 1 2
	// 2 3
	// 3 1
	// 2 4
	// 4 5

	int num_of_nodes, edges;
	cin >> num_of_nodes >> edges;

	vector<int> adj[num_of_nodes+1];

	for (int i = 0; i < edges; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
	}

	stack<int> st;
	vector<int> vis(num_of_nodes+1, 0);

	for (int i = 1; i <= num_of_nodes; i++) {
		if (!vis[i]) dfs(i, st, vis, adj);
	}

	vector<int> transpose[num_of_nodes+1];

	for (int i = 1; i <= num_of_nodes; i++) {
		vis[i] = 0;
		for (auto it: adj[i]) transpose[it].push_back(i);
	}

	while (!st.empty()) {
		int node = st.top();
		st.pop();

		if (!vis[node]) {
			cout << "SCC: ";
			revDFS(node, vis, transpose);
			cout << "\n";
		}
	}

	return 0;
}
