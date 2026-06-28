#include <iostream>
#include <vector>

using namespace std;

class Solution {
    private:
        bool dfs(int node, int parent, vector<int>&vis, vector<int>adj[]) {
            vis[node] = 1;

            for(auto adjNode : adj[node]) {
                if(!vis[adjNode]) {
                    if(dfs(adjNode, node, vis, adj)) return true;
                }
                else if(adjNode != parent) return true;
            }
            return false;
        }
    public:
        bool isCycle(vector<int>adj[], int V) {
            vector<int>vis(V, 0);

            for(int i = 0; i < V; i++) {
                if(!vis[i]) {
                    if(dfs(i, -1, vis, adj)) return true;
                }
            }
            return false;
        }
};

/* Time : O(N + 2E) , Space: O(N) */

int main() {
    int V = 6;
    vector<int>adj[V];
    adj[0] = {1, 3};
    adj[1] = {0, 2, 4};
    adj[2] = {1, 5};
    adj[3] = {0, 4};
    adj[4] = {1, 3, 5};
    adj[5] = {2, 4};

    Solution sol;
    cout << "Cycle in given list: ";
    cout << sol.isCycle(adj, V) << endl;

}