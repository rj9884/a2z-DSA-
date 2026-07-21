#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class DisjointSet {
public:
    vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
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
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    bool isValid(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }

    void addInitialIslands(vector<vector<int>> &grid, DisjointSet &ds, int n) {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) {
                    continue;
                }

                for (int i = 0; i < 4; i++) {
                    int newRow = row + delRow[i];
                    int newCol = col + delCol[i];

                    if (isValid(newRow, newCol, n) && grid[newRow][newCol] == 1) {
                        int node = row * n + col;
                        int adjNode = newRow * n + newCol;

                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }
    }

public:
    int largestIsland(vector<vector<int>> &grid) {
        int n = grid.size();

        DisjointSet ds(n * n);

        addInitialIslands(grid, ds, n);

        int ans = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    continue;
                }

                set<int> components;

                for (int i = 0; i < 4; i++) {
                    int newRow = row + delRow[i];
                    int newCol = col + delCol[i];

                    if (isValid(newRow, newCol, n) && grid[newRow][newCol] == 1) {
                        int node = newRow * n + newCol;
                        components.insert(ds.findUPar(node));
                    }
                }

                int totalSize = 0;

                for (int parent : components) {
                    totalSize += ds.size[parent];
                }

                ans = max(ans, totalSize + 1);
            }
        }

        for (int node = 0; node < n * n; node++) {
            ans = max(ans, ds.size[ds.findUPar(node)]);
        }

        return ans;
    }
};

/*Time: O(N^2), Space: O(N^2) */

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {1, 0},
        {0, 1}
    };

    cout << obj.largestIsland(grid) << endl;

    return 0;
}