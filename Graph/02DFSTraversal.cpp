#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void dfs(int node, vector<int>&vis, vector<int>adj[], vector<int>&ls) {
            vis[node] = 1;
            ls.push_back(node);

            for(auto it : adj[node]) {
                if(!vis[it]) {
                    dfs(it, vis, adj, ls);

                }
            }
        }

        vector<int> dfsOfGraph(int V, vector<int> adj[]) {
            vector<int>vis(V, 0);
            int start = 0;
            vector<int>ls;
            dfs(0,vis, adj, ls);

            return ls;
        }
};


void printAns(vector<int>&ans) {
    for(auto val : ans) {
        cout << val << " ";
    }
    cout << endl;
}

/* time : O(N) , Space : O(N) + O(2 * E) */

int main() {
    int V = 5;

    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    Solution sol;
    vector<int>res = sol.dfsOfGraph(V, adj);
    printAns(res);
}