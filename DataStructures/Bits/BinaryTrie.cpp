template <typename IntegerType = int, int INT_SIZE = 31, int capacity = 1e5>
struct BinaryTrie {
    int nxt[capacity][2]{}, freq[capacity]{}, nodesCount;

    BinaryTrie() {
        nodesCount = 0;
    }

    void add(const IntegerType& x) {
        int node = 0;
        for (int i = INT_SIZE; i >= 0; --i) {
            bool bit = (x >> i) & 1;

            if (nxt[node][bit] == 0)
                nxt[node][bit] = ++nodesCount;

            node = nxt[node][bit];
            ++freq[node];
        }
    }

    void erase(const IntegerType& x) {
        int node = 0;
        for (int i = INT_SIZE; i >= 0; --i) {
            bool bit = (x >> i) & 1;
            node = nxt[node][bit];
            --freq[node];
        }
    }

    IntegerType getMin(const IntegerType& x) {
        IntegerType res = 0;
        int node = 0;
        for (int i = INT_SIZE; i >= 0; --i) {
            bool bit = (x >> i) & 1;
            if (nxt[node][bit] != 0 && freq[nxt[node][bit]]) {
                node = nxt[node][bit];
            }
            else {
                node = nxt[node][bit ^ 1];
                res |= (1LL << i);
            }
        }

        return res;
    }

    IntegerType getMax(const IntegerType& x) {
        IntegerType res = 0;
        int node = 0;
        for (int i = INT_SIZE; i >= 0; --i) {
            bool bit = (x >> i) & 1;
            if (nxt[node][bit ^ 1] != 0 && freq[nxt[node][bit ^ 1]]) {
                node = nxt[node][bit ^ 1];
                res |= (1LL << i);
            }
            else {
                node = nxt[node][bit];
            }
        }

        return res;
    }
};