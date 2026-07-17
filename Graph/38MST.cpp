#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int primMST(int V, vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> adj(V);

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        vector<bool> visited(V, false);

        pq.push({0, 0});
        int mstWeight = 0;

        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (visited[node]) {
                continue;
            }

            visited[node] = true;
            mstWeight += wt;

            for (auto &[adjNode, edgeWt] : adj[node]) {
                if (!visited[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }

        return mstWeight;
    }
};

int main() {
    Solution obj;

    int V = 5;

    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7}
    };

    cout << obj.primMST(V, edges) << endl;

    return 0;
}