#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool hasCycle(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return count != V;
    }
};

/* Time: O(V + E) , Space: O(V + E) */

int main() {
    int V = 4;
    vector<vector<int>> adj = {
        {1}, {2}, {3}, {1}
    };

    Solution obj;
    if (obj.hasCycle(V, adj))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";
    return 0;
}
