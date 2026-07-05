#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution{
private:
    void dfs(vector<int> adj[], int node, vector<int>&vis, stack<int>&st) {
        vis[node] = 1;

        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(adj, it, vis, st);
            }
        }
        st.push(node);
    }
public:
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int>vis(V, 0);
        stack<int>st;
        vector<int>ans;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(adj, i, vis, st);
            }
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};


/* Time: O(V + E) , Space: O(V + E) */

int main() {
    int V = 6;
   vector<int> adj[V];
   adj[0] = {};
   adj[1] = {};
   adj[2] = {3};
   adj[3] ={1};
   adj[4] = {0, 1};
   adj[5] = {0, 2};

    Solution sol;
    vector<int>ans = sol.topoSort(V, adj);
    cout << "Topological Sort: " << endl;

    for(auto val : ans) {
        cout << val << " ";
    }
    cout << endl;
}