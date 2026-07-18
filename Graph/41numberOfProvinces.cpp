#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
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

    void unionByRank(int u, int v) {
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
    int numProvinces(vector<vector<int>> &adj, int V) {
        DisjointSet ds(V);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1 && i != j) {
                    ds.unionByRank(i, j);
                }
            }
        }

        int count = 0;

        for (int i = 0; i < V; i++) {
            if (ds.find(i) == i) {
                count++;
            }
        }

        return count;
    }
};

/*Time: O(V^2) where V is the number of vertices
Space: O(V) where V is the number of vertices */

int main() {
    Solution obj;

    vector<vector<int>> adj = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    cout << obj.numProvinces(adj, 3) << endl;

    return 0;
}