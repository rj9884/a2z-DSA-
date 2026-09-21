#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int timer = 0;

    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis,
             vector<int> &tin, vector<int> &low,
             vector<vector<int>> &bridges) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for (auto it : adj[node]) {
            if (it == parent)
                continue;

            if (!vis[it]) {
                dfs(it, node, adj, vis, tin, low, bridges);

                low[node] = min(low[node], low[it]);

                if (low[it] > tin[node]) {
                    bridges.push_back({node, it});
                }
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }
    }

public:
    vector<vector<int>> findBridges(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> tin(V, -1);
        vector<int> low(V, -1);
        vector<vector<int>> bridges;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis, tin, low, bridges);
            }
        }

        return bridges;
    }
};

int main() {
    int V = 5;

    int edges[5][2] = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3},
        {3, 4}
    };

    vector<int> adj[V];

    for (int i = 0; i < 5; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;

    vector<vector<int>> bridges = obj.findBridges(V, adj);

    cout << "Bridges:\n";

    for (auto bridge : bridges) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}