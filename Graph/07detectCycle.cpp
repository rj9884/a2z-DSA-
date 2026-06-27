#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    private:
        bool bfs(vector<int>adj[], vector<int>&vis, int src) {
            vis[src] = 1;
            queue<pair<int, int>>q;
            q.push({src, -1});

            while(!q.empty()) {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for(auto adjNode : adj[node]) {
                    if(!vis[adjNode]) {
                        vis[adjNode] = 1;
                        q.push({adjNode, node});
                    }
                    else if(parent != adjNode) return true;
                }
            }
            return false;
        }
        bool bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int sr, int sc) {
            int n = grid.size();
            int m = grid[0].size();

            queue<pair<pair<int,int>, pair<int,int>>> q;
            // {{row, col}, {parentRow, parentCol}}

            q.push({{sr, sc}, {-1, -1}});
            vis[sr][sc] = 1;

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            while (!q.empty()) {

                auto front = q.front();
                q.pop();

                int row = front.first.first;
                int col = front.first.second;
                int prow = front.second.first;
                int pcol = front.second.second;

                for (int k = 0; k < 4; k++) {

                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                        continue;

                    if (grid[nr][nc] != grid[row][col])
                        continue;

                    if (!vis[nr][nc]) {
                        vis[nr][nc] = 1;
                        q.push({{nr, nc}, {row, col}});
                    }
                    else if (!(nr == prow && nc == pcol)) {
                        return true;
                    }
                }
            }

            return false;
        }
    public:
        bool containsCycle(vector<vector<char>>& grid) {
            int n = grid.size();
            int m = grid[0].size();

            vector<vector<int>> vis(n, vector<int>(m, 0));

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {

                    if (!vis[i][j]) {
                        if (bfs(grid, vis, i, j))
                            return true;
                    }
                }
            }

            return false;
        }
        bool containsCycle(vector<int>adj[], int V) {
            vector<int>vis(V, 0);
            for(int i = 0; i < V; i++) {
                if(!vis[i]) {
                    if(bfs(adj, vis, i))
                        return true;
                }
            }
            
            return false;
        }
};

/*
for adj list
Time : O(N + 2E)
Space : O(N) */

/*for 2d grid
Time: O(N * M)
Space: O(N * M) */

int main() {
    int V = 6;
    vector<int>adj[V];
    adj[0] = {1, 3};
    adj[1] = {0, 2, 4};
    adj[2] = {1, 5};
    adj[3] = {0, 4};
    adj[4] = {1, 3, 5};
    adj[5] = {2, 4};

    vector<vector<char>>grid = {
        {'a', 'a', 'a', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'a', 'a', 'a'}
    };

    Solution sol;
    cout << "Cycle is given list: ";
    cout << sol.containsCycle(adj, V) << endl;

    cout << "cycle in given 2D grid: " << sol.containsCycle(grid) << endl;

}