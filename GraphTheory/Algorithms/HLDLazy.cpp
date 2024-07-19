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
int lazy[S];

Node merge(const Node& a, const Node& b) {
    return {a.val + b.val};
}

void push(int idx, int l, int r) {
    if (lazy[idx] != 0) {
        st[idx].val += lazy[idx] * (r - l + 1);
        if (l != r) {
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void update_range(int lo, int hi, int l, int r, int idx, int value) {
    push(idx, l, r);
    if (lo > r || hi < l) return;
    if (lo <= l && r <= hi) {
        lazy[idx] += value;
        push(idx, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update_range(lo, hi, l, mid, idx * 2, value);
    update_range(lo, hi, mid + 1, r, idx * 2 + 1, value);
    st[idx] = merge(st[idx * 2], st[idx * 2 + 1]);
}

void update(int idx, Node val) {
    update_range(idx, idx, 0, n - 1, 1, val.val);
}

void update_range(int lo, int hi, int value) {
    update_range(lo, hi, 0, n - 1, 1, value);
}

Node query(int lo, int hi, int l, int r, int idx) {
    push(idx, l, r);
    if (lo > r || hi < l) return nullNode;
    if (lo <= l && r <= hi) return st[idx];
    int mid = (l + r) / 2;
    return merge(query(lo, hi, l, mid, idx * 2), query(lo, hi, mid + 1, r, idx * 2 + 1));
}

Node query(int lo, int hi) {
    return query(lo, hi, 0, n - 1, 1);
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

int get(int u) {
    return query(id[u], id[u]).val;
}

void path(int u, int v, int val) {
    // Node ans = nullNode;

    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        // ans = merge(ans, query(id[top[u]], id[u]));
        update_range(id[top[u]], id[u], val);
        u = par[top[u]];
    }

    if (dep[u] > dep[v]) swap(u, v);
    // ans = merge(ans, query(id[u], id[v]));
    update_range(id[u], id[v], val);
    // return ans;
}

void init() {
    for (int i = 0; i < S; i++) st[i] = nullNode;
    memset(lazy, 0, sizeof(lazy));
    dfs_size(1, 1);
    dfs_hld(1, 1, 1);
}

int main(void) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) val[i] = 0;
    int a, b;
    for (int i = 2; i <= n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    init(); // <---------------- DON'T FORGET TO CALL THIS FUNCTION
    int v;
    while (q--) {
        cin >> a >> b >> v;
        path(a, b, v);
    }

    for (int i = 1; i <= n; i++) {
        cout << get(i) << " ";
    }
    cout << el;
}
