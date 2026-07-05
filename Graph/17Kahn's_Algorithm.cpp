#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution{
public:
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int>indegree(V, 0);

        for(int i = 0; i < V; i++) {
            for(auto adjNode : adj[i]) {
                indegree[adjNode]++;
            }
        }
        queue<int>q;
        vector<int>topo;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return topo;
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
    cout << "Topological Sort using BFS/Kahn Algorithm: " << endl;

    for(auto val : ans) {
        cout << val << " ";
    }
    cout << endl;
}
