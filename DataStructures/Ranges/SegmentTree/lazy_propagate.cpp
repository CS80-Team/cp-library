struct SegTree {
private:
    void propegate(int lx, int rx, int node) {
        if(!lazy[node]) return;

        if(lx != rx) {
            lazy[2*node+1] = lazy[node];
            lazy[2*node+2] = lazy[node];
        }
        values[node] = lazy[node] * (rx - lx + 1);
        lazy[node] = 0;
    }

    // assign val in range [l, r]
    void update_range(int l, int r, int node, int lx, int rx, int val, bool f) {
        propegate(lx, rx, node);
        if (lx > r || l > rx) return;
        if (lx >= l && rx <= r) {
            lazy[node] = val;
            propegate(lx, rx, node);
            return;
        }
        int mid = (lx+rx) / 2;

        update_range(l, r, 2*node+1, lx, mid, val, f);
        update_range(l, r, 2*node+2, mid+1, rx, val, f);
        values[node] = values[2*node+1] + values[2*node+2];
    }

    // get sum in range [l, r]
    int range_query(int l, int r, int lx, int rx, int node) {
        propegate(lx, rx, node);
        if (lx > r || l > rx) return 0;
        if (lx >= l && rx <= r) return values[node];

        int mid = (lx+rx) / 2;
        return range_query(l, r, lx, mid, 2*node+1) + range_query(l, r, mid+1, rx, 2*node+2);
    }

public:
    int size{};
    vector<int> values, lazy;

    void init(int _size) {
        size = 1;
        while (size < _size) size *= 2;
        values.assign(2 * size, 0);
        lazy.assign(2 * size, 0);
    }

    void update_range(int l, int r, int v, bool f) {
        update_range(l, r, 0, 0, size-1, v, f);
    }

    int range_query(int l, int r) {
        return range_query(l, r, 0, size-1, 0);
    }
};
