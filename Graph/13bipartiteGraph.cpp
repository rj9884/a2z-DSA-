#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution{
    private:
        bool bfs(vector<vector<int>>&graph, int start, vector<int>&color) {
            queue<int>q;
            q.push(start);

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(int adjNode : graph[node]) {
                    if(color[adjNode] == -1) {
                        color[adjNode] = !color[node];
                        q.push(adjNode);
                    }
                    else if(color[adjNode] == color[node]) return false;
                }
            }
            return true;
        }
    public:
        bool isBipartite(vector<vector<int>> &graph) {
            int n = graph.size();
            vector<int>color(n, -1);

            for(int i = 0; i < n; i++) {
                if(color[i] == -1) {
                    if(!bfs(graph, i, color)) return false;
                }
            }
            return true;
        }
};

/* Time: O(V + E) , Space: O(V) */

int main() {
    vector<vector<int>>graph = {
        {1,3},{0,2},{1,3},{0,2}
    };
    Solution sol;
    cout << "The Given Graph is ";
    (sol.isBipartite(graph)) ? cout << "Bipartite\n" : cout << "NOT Bipartite\n"; 
    return 0;
}