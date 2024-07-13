 vector <vector <pair<int, int>>> &adj
 
vector <long long> BellmanFord(int src) {
    int n = (int)adj.size();
    vector <long long> dist(n, 2e18);

    dist[src] = 0;
    for (int it = 0; it < n-1; it++) {
        bool in = false;
        for (int i = 0; i < n; i++) { // iterate on the edges
            for (auto &[j, w] : adj[i]) {
                if (dist[j] > dist[i] + w) {
                    in = true;
                    dist[j] = dist[i] + w;
                }
            }
        }
        if (!in) return dist;
    }

    for (int i = 0; i < n; i++) {
        for (auto &[j, w] : adj[i]) {
            if (dist[j] > dist[i] + w) { //negative cycle
                return vector <long long> (n, -1); // or any flag
            }
        }
    }
	
    return dist;
}