#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;

        for (int i = 0; i < V - 1; i++) {
            for (auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1};
            }
        }

        return dist;
    }
};

/* Time: O(V*E), Space : O(V) */

int main() {
    Solution obj;

    int V = 6;
    vector<vector<int>> edges = {
        {0, 1, 5},
        {1, 2, -2},
        {1, 5, -3},
        {2, 4, 3},
        {3, 2, 6},
        {3, 4, -2}
    };

    int S = 0;

    vector<int> ans = obj.bellman_ford(V, edges, S);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}