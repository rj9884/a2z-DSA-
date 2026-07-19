#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) {
            return;
        }

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>> &connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        DSU dsu(n);

        for (auto &edge : connections) {
            dsu.unite(edge[0], edge[1]);
        }

        unordered_set<int> components;

        for (int i = 0; i < n; i++) {
            components.insert(dsu.find(i));
        }

        return components.size() - 1;
    }
};

/*Time: O(N + M × α(N)), Space: O(N) */

int main() {
    Solution obj;

    int n = 6;

    vector<vector<int>> connections = {
        {0, 1},
        {0, 2},
        {0, 3},
        {1, 4}
    };

    cout << obj.makeConnected(n, connections) << endl;

    return 0;
}