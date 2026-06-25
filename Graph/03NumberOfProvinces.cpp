#include<iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>> & edges, vector<int>&vis, int start) {
        vis[start] = 1;

        for(int i = 0; i < edges.size(); i++) {
            if(edges[start][i] == 1 && !vis[i]) {
                dfs(edges, vis, i);
            }
        }
        return;
    }
    void bfs(vector<vector<int>> & edges, vector<int>&vis, int start) {
        vis[start] = 1;
        queue<int>q;
        q.push(start);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int i = 0; i < edges.size(); i++) {
                if(edges[start][i] == 1 && !vis[i]) {
                vis[i] = 1;
                q.push(i);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int>vis(V, 0);
        int province = 0;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(isConnected, vis, i);
                // bfs(isConnected, vis, i);
                province++;
            }
        }
        return province;
    }
};

/* time : O(N) + O(V + 2E) , Space : O(N) */
int main() {
    vector<vector<int>>isConnected = {{1,1,0},{1,1,0},{0,0,1}};

    Solution sol;

    cout << "Number of Provinces is: " << sol.findCircleNum(isConnected);
    cout << endl;
}