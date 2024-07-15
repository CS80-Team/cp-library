struct Node {
    long long val;
};

struct SegTree {
private:
    const Node NEUTRAL = {INT_MIN};

    static Node merge(const Node& x1, const Node& x2) {
        return {x1.val + x2.val};
    }

    void set(const int& idx, const int& val, int x, int lx, int rx) {
        if (rx - lx == 1) return void(values[x].val = val);

        int mid = (rx + lx) / 2;

        if (idx < mid)
            set(idx, val, 2 * x + 1, lx, mid);
        else
            set(idx, val, 2 * x + 2, mid, rx);

        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    Node query(const int& l, const int& r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return NEUTRAL;
        if (lx >= l && rx <= r) return values[x];

        int mid = (rx + lx) / 2;

        return merge(query(l, r, 2 * x + 1, lx, mid), query(l, r, 2 * x + 2, mid, rx));
    }
    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) {
                values[x].val = a[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

     void assign_range(int l, int r, int node, int lx, int rx, int time, int val) {
        if (lx > r || l > rx) return;
        if (lx >= l && rx <= r) {
            lazy[node] = {time, val};
            return;
        }
        int mid = (lx+rx) / 2;

        assign_range(l, r, 2*node+1, lx, mid, time, val);
        assign_range(l, r, 2*node+2, mid+1, rx, time, val);
    }

    pair<int, int> point_query(int lx, int rx, int node, int idx) {
        if(rx == lx) return lazy[node];
        int mid = (lx+rx) / 2;

        if(idx <= mid) {
            auto x = point_query(lx, mid, 2*node+1, idx);
            if(x.first > lazy[node].first) return x;
            return lazy[node];
        }
        auto x = point_query(mid+1, rx, 2*node+2, idx);
        if(x.first > lazy[node].first) return x;
        return lazy[node];
    }

public:
    int size{};
    vector<Node> values;

    void build(vector<int> &a) {
        build(a, 0, 0, size);
    }

    void init(int _size) {
        size = 1;
        while (size < _size) size *= 2;
        values.assign(2 * size, NEUTRAL);
    }

    void set(int idx, int val) {
        set(idx, val, 0, 0, size);
    }

    Node query(const int& l, const int& r) {
        return query(l, r, 0, 0, size);
    }
};
