#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int timer = 0;

    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis,
             vector<int> &tin, vector<int> &low, vector<int> &isArticulation) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;

        int children = 0;

        for (auto it : adj[node]) {
            if (it == parent)
                continue;

            if (!vis[it]) {
                children++;

                dfs(it, node, adj, vis, tin, low, isArticulation);

                low[node] = min(low[node], low[it]);

                if (parent != -1 && low[it] >= tin[node]) {
                    isArticulation[node] = 1;
                }
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }

        if (parent == -1 && children > 1) {
            isArticulation[node] = 1;
        }
    }

public:
    vector<int> findArticulationPoints(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> tin(V, -1);
        vector<int> low(V, -1);
        vector<int> isArticulation(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis, tin, low, isArticulation);
            }
        }

        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (isArticulation[i]) {
                ans.push_back(i);
            }
        }

        return ans;
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

    vector<int> ans = obj.findArticulationPoints(V, adj);

    cout << "Articulation Points:\n";

    for (auto node : ans) {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}