#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    void dfs(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &vis) {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + dRow[i];
            int ncol = col + dCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(grid, nrow, ncol, vis);
            }
        }
    }
public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++) {
            if(!vis[0][j] && grid[0][j] == 1) {
                dfs(grid, 0, j, vis);
            }
            if(!vis[n-1][j] && grid[n-1][j] == 1) {
                dfs(grid, n-1, j, vis);
            }
        }
        for(int i= 0; i < m; i++) {
            if(!vis[i][0] && grid[i][0] == 1) {
                dfs(grid, i, 0, vis);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1) {
                dfs(grid, i, m-1, vis);
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};

/* time : O(N * M), O(N * M) */

int main() {
    vector<vector<int>>grid = {
        {0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}
    };

    Solution sol;
    cout << "No. of Enclaves is : " << sol.numberOfEnclaves(grid) << endl;
}