#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;

public:
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
    bool isValid(int row, int col, int n, int m) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n * m);

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;
        vector<int> ans;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (auto &it : operators) {
            int row = it[0];
            int col = it[1];

            if (vis[row][col]) {
                ans.push_back(cnt);
                continue;
            }

            vis[row][col] = 1;
            cnt++;

            for (int i = 0; i < 4; i++) {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (isValid(newRow, newCol, n, m) && vis[newRow][newCol]) {
                    int node = row * m + col;
                    int adjNode = newRow * m + newCol;

                    if (ds.findUPar(node) != ds.findUPar(adjNode)) {
                        cnt--;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};

/*Time: O(N * M) , Space: O(N * M) */

int main() {
    Solution obj;

    int n = 4;
    int m = 5;

    vector<vector<int>> operators = {
        {0, 0}, {0, 0}, {1, 1}, {1, 0},
        {0, 1}, {0, 3}, {1, 3}, {0, 4},
        {3, 2}, {2, 2}, {1, 2}, {0, 2}
    };

    vector<int> ans = obj.numOfIslands(n, m, operators);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}