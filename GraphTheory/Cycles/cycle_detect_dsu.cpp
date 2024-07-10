#include <iostream>
#include <vector>

class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                ++rank[rootU];
            }
        }
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

bool detectCycle(const std::vector<std::pair<int, int>>& edges, int n) {
    UnionFind uf(n);

    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;

        if (uf.find(u) == uf.find(v)) {
            return true;
        }
        uf.unionSets(u, v);
    }

    return false;
}

int main() {
    std::vector<std::pair<int, int>> edges = { {0, 1}, {1, 2}, {2, 3}, {3, 0} };
    int n = 4; // Number of vertices

    if (detectCycle(edges, n)) {
        std::cout << "Cycle detected" << std::endl;
    } else {
        std::cout << "No cycle detected" << std::endl;
    }

    return 0;
}

