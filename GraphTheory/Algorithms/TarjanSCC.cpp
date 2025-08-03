struct TarjanSCC {
    vector<vector<int>> adj;
    vector<int> idx, lowLink;
    vector<bool> onStack;
    stack<int> st;
    int _size, components, timer;
    vector<vector<int>> sccs;

    explicit TarjanSCC(const int& n, const vector<vector<int>>& graph) : adj(graph), _size(n) {
        components = 0;
        timer = 0;

        onStack.assign(n + 1, false);
        idx.assign(n + 1, -1);
        lowLink.assign(n + 1, -1);

        for (int node = 1; node <= n; ++node) if (idx[node] == -1) dfs(node);

        ranges::sort(all(sccs), [](const vector<int>& a, const vector<int>& b) {
            return a.size() > b.size();
        });
    }

    void dfs(const int& node) {
        idx[node] = timer;
        lowLink[node] = timer++;
        onStack[node] = true;
        st.push(node);

        for (const int& ch : adj[node]) {
            if (idx[ch] == -1) {
                dfs(ch);
                lowLink[node] = min(lowLink[node], lowLink[ch]);
            } else if (onStack[ch]) {
                lowLink[node] = min(lowLink[node], lowLink[ch]);
            }
        }

        if (idx[node] == lowLink[node]) {
            vector<int> scc;
            int cur = -1;
            while (cur != node) {
                cur = st.top();
                st.pop();
                onStack[cur] = false;
                scc.push_back(cur);
            }

            sccs.push_back(scc);
            components++;
        }
    }

    int getLargestCompSize() const {
        return sccs.front().size();
    }

    vector<int> getLargestComp() const {
        return sccs.front();
    }

    vector<vector<int>> getAllComp() const {
        return this->sccs;
    }
};

void run_test_case(int testNum) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    int a, b;
    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    const TarjanSCC tar(n, adj);

    cout << tar.components << el;
    for (const int &i : tar.getLargestComp()) {
        cout << i << " ";
    }
}