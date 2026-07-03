#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  private: 
  bool detect(int src, vector<int> adj[], vector<int>&vis) {
      vis[src] = 1; 
      queue<pair<int,int>> q; 
      q.push({src, -1}); 
      while(!q.empty()) {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          for(auto adjacentNode: adj[node]) {
              if(!vis[adjacentNode]) {
                  vis[adjacentNode] = 1; 
                  q.push({adjacentNode, node}); 
              }
              else if(parent != adjacentNode) {
                  return true; 
              }
          }
      }
      return false; 
  }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V, 0);
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true; 
            }
        }
        return false; 
    }
};


/* Time: O(N + E) , O(N) */

int main() {
    
    vector<int> adj[6] = {
        {1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}
    };
    Solution obj;
    bool ans = obj.isCycle(6, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}
