//REF: USACO Guide
vector<int> top_sort;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node) {
	for (int next : graph[node]) {
		if (!visited[next]) {
			visited[next] = true;
			dfs(next);
		}
	}
	top_sort.push_back(node);
}

int main() {
	int n, m;  // The number of nodes and edges respectively
	std::cin >> n >> m;

	graph = vector<vector<int>>(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		graph[a - 1].push_back(b - 1);
	}

	visited = vector<bool>(n);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i);
		}
	}
	std::reverse(top_sort.begin(), top_sort.end());

	vector<int> ind(n);
	for (int i = 0; i < n; i++) { ind[top_sort[i]] = i; }

	// Check if the topological sort is valid
	bool valid = true;
	for (int i = 0; i < n; i++) {
		for (int j : graph[i]) {
			if (ind[j] <= ind[i]) {
				valid = false;
				goto answer;
			}
		}
	}
answer:;

	if (valid) {
		for (int i = 0; i < n - 1; i++) { cout << top_sort[i] + 1 << ' '; }
		cout << top_sort.back() + 1 << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
}