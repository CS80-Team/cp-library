struct Node {
    int val;
};

const Node nullNode = {0};

const int N = 2e5 + 5, S = 1 << 19;
int n, q;
int val[N];
int sz[N], par[N], dep[N], id[N], top[N];
vector<int> adj[N];

Node st[S];

Node merge(const Node& a, const Node& b) {
    return {a.val + b.val};
}

void update(int idx, Node val) {
    st[idx += n] = val;
    for (idx /= 2; idx; idx /= 2) st[idx] = merge(st[idx * 2], st[idx * 2 + 1]);
}

Node query(int lo, int hi) {
    Node ra = nullNode, rb = nullNode;

    for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2) {
        if (lo & 1) ra = merge(ra, st[lo++]);
        if (hi & 1) rb = merge(st[--hi], rb);
    }

    return merge(ra, rb);
}

int dfs_size(const int& node, const int& parent) {
    sz[node] = 1;
    par[node] = parent;
    for (const int& ch : adj[node]) {
        if (ch == parent) continue;
        dep[ch] = dep[node] + 1;
        par[ch] = node;
        sz[node] += dfs_size(ch, node);
    }
    return sz[node];
}

int curId = 0;

void dfs_hld(const int& cur, const int& parent, const int& curTop) {
    id[cur] = curId++;
    top[cur] = curTop;
    update(id[cur], {val[cur]});
    int heavyChild = -1, heavyMax = -1;
    for (const int& ch : adj[cur]) {
        if (ch == parent) continue;
        if (sz[ch] > heavyMax) {
            heavyMax = sz[ch];
            heavyChild = ch;
        }
    }

    if (heavyChild == -1) return;
    dfs_hld(heavyChild, cur, curTop);
    for (int ch : adj[cur]) {
        if (ch == parent || ch == heavyChild) continue;

        dfs_hld(ch, cur, ch);
    }
}

Node path(int u, int v) {
    Node ans = nullNode;

    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        ans = merge(ans, query(id[top[u]], id[u]));
        u = par[top[u]];
    }

    if (dep[u] > dep[v]) swap(u, v);
    ans = merge(ans, query(id[u], id[v]));
    return ans;
}

void init() {
    for (int i = 0; i < S; i++) st[i] = nullNode;
    dfs_size(1, 1);
    dfs_hld(1, 1, 1);
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> val[i];

    int a, b;
    for (int i = 2; i <= n; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    init(); // <---------------- DON'T FORGET TO CALL THIS FUNCTION

    int type;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> a >> b;
            val[a] = b;
            update(id[a], {val[a]});
        }
        else {
            cin >> a;
            cout << path(1, a).val << el;
        }
    }
}