#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) {
            return;
        }

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) {
            return;
        }

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;

        for (int u = 0; u < V; u++) {
            for (auto &it : adj[u]) {
                int v = it[0];
                int wt = it[1];
                edges.push_back({wt, {u, v}});
            }
        }

        sort(edges.begin(), edges.end());

        DisjointSet ds(V);

        int sum = 0;

        for (auto &it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v)) {
                sum += wt;
                ds.unionBySize(u, v);
            }
        }

        return sum;
    }
};

/*Time: O(E * log E) where E is the number of edges
Space: O(V) where V is the number of vertices */

int main() {
    Solution obj;

    int V = 4;

    vector<vector<int>> edges = {
        {0, 1, 1},
        {1, 2, 2},
        {2, 3, 3},
        {0, 3, 4}
    };

    vector<vector<int>> adj[4];

    for (auto &it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    cout << obj.spanningTree(V, adj) << endl;

    return 0;
}