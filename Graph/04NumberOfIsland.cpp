#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    void bfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>> & vis) {
        vis[row][col] = 1;
        queue<pair<int , int>>q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int cntIsland = 0;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(!vis[row][col] && grid[row][col] == '1') {
                    bfs(grid, row, col, vis);
                    cntIsland++;
                }
            }
        }
        return cntIsland;
    }
};

/* ti,e : O(N^2) , Space : O(N^2) */

int main() {
    vector<vector<char>>grid = {
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}
    };

    Solution sol;

    cout << "Total No. of Island: " << sol.numIslands(grid);
    cout << endl;
}