const int N = 2e5 + 15, M = 23;
int ancestors[N][M], depth[N], parent[N], val[N];
vector<vector<int>> adj;
//int tin[N], tout[N], timer;
 
void dfs_LCA(const int &node, const int &par) {
//    tin[node] = timer++;
    parent[node] = par;
    ancestors[node][0] = par;
    depth[node] = depth[par] + 1;
 
    for (int i = 1; i < M; i++) {
        int p = ancestors[node][i - 1];
        ancestors[node][i] = ancestors[p][i - 1];
    }
 
    for (const int &v: adj[node]) {
        if (v == par) continue;
        dfs_LCA(v, node);
    }
//    tout[node] = timer++;
}
 
//bool is_ancestor(int u, int v) {
//    return tin[u] <= tin[v] && tout[u] >= tout[v];
//}
 
int findKth(int u, int k) {
    if (depth[u] <= k) return -1;
    for (int i = M - 1; i >= 0; i--) {
        if (k & (1 << i)) {
            u = ancestors[u][i];
        }
    }
    return u;
}
 
int getLCA(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
 
    u = findKth(u, depth[u] - depth[v]);
    if (u == v) return u;
 
    for (int i = M - 1; i >= 0; i--) {
        if (ancestors[u][i] == ancestors[v][i]) continue;
        u = ancestors[u][i];
        v = ancestors[v][i];
    }
    return ancestors[u][0];
}
 
int getDistance(int u, int v) {
    int lca = getLCA(u, v);
    return (depth[u] + depth[v]) - (2 * depth[lca]);
}
 
int dfs_accumulate(const int &node, const int &par) {
 
    for (const int& ch: adj[node]) {
        if (ch == par) continue;
        val[node] += dfs_accumulate(ch, node);
    }
    return val[node];
}
 
void applyOpOnPath(const int a, const int b, const int w) {
    // adding w to each node on the path a to b
    val[a] += w;
    val[b] += w;
    int lca = getLCA(a, b);
    val[lca] -= w;
    val[parent[lca]] -= w;
}
 
int main(void) {
    int n, q;
    cin >> n >> q;
    adj.resize(n + 1);
 
    int u, v;
    for (int i = 2; i <= n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dfs_LCA(1, 1);
    parent[1] = -1;
 
    int w;
    for (int i = 0; i < q; ++i) {
        cin >> u >> v;
        cout << getDistance(u, v) << el;
    }
 
//    dfs_accumulate(1, 0);
//
//    for (int i = 1; i <= n; i++) {
//        cout << val[i] << " ";
//    }
//    cout << el;
}