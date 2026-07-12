#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> edges, int S) {

        vector<vector<pair<int, int>>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); 
        }

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        vector<int> dist(V, 1e9);
        dist[S] = 0;

        pq.push({0, S});

        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node])
                continue;

            for (auto &it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                if (dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

/* Time: O((V+E)logV), Space: O(V+E) */

int main() {
    int V = 3;
    vector<vector<int>> edges = {
        {0, 1, 1},
        {0, 2, 6},
        {1, 2, 3}
    };
    int S = 2;

    Solution obj;
    vector<int> ans = obj.dijkstra(V, edges, S);

    cout << "Shortest distances from source " << S << ":\n";
    cout << "[";
    for (int i = 0; i < V; i++) {
        cout << ans[i];
        if (i != V - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}