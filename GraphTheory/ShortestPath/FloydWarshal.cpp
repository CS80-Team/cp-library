int main() {
    int n, m; cin >> n >> m;
    vector <vector <int>> adj(n + 1, vector <int> (n + 1, 2e9));
    for (int i = 0; i < n; i++) adj[i][i] = 0;
	
    while(m--) {
        int u, v, w; 
		cin >> u >> v >> w;
        adj[u][v] = min(adj[u][v], w);
        adj[v][u] = min(adj[v][u], w);
    }

    for (int mid = 1; mid <= n; mid++) { 
        for (int start = 1; start <= n; start++) {
            for (int end = 1; end <= n; end++) {
                adj[start][end] = min(adj[start][end], adj[start][mid] + adj[mid][end]);
            }
        }
    }
	
	return 0;
}