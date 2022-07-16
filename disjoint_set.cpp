#include <bits/stdc++.h>

//Ctrl+Alt+F    To format the code
//Ctrl+B        To run the code
//Ctrl+/        To comment the lines completly
//Ctrl+Shift+/  To comment the required/selected lines only

using namespace std;

// r = Rank
int parent[100000], r[100000];

void makeSet() {
	for (int i = 1; i <= 100000; i++) {
		parent[i] = i;
		r[i] = 0;
	}
}

int findParent(int node) {
	if (node == parent[node]) return node;
	return parent[node] = findParent(parent[node]);
}

void uni(int u, int v) {
	u = findParent(u);
	v = findParent(v);

	if (r[u] < r[v]) parent[u] = v;
	else if (r[v] < r[u]) parent[v] = u;
	else {
		parent[v] = u;
		r[u]++;
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	makeSet();

	int m;
	cin >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		uni(u, v);
	}

	if (findParent(1) != findParent(3)) {
		cout << "Different Component\n";
	} else {
		cout << "Same Component\n";
	}

	return 0;
}
