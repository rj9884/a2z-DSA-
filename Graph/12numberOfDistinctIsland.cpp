#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
private:
    void dfs(vector<vector<int>> &grid, int row, int col, vector<vector<int>>&vis, vector<pair<int , int>>&vec, int row0, int col0) {
        int n = grid.size();
        int m  = grid[0].size();
        vis[row][col] = 1;
        vec.push_back({row - row0, col - col0});

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + dRow[i];
            int ncol = col + dCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
            && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(grid, nrow, ncol, vis, vec, row0, col0);
            }
        }
    }
public:
    int countDistinctIslands(vector<vector<int>> &grid){
        int n = grid.size();
        int m  = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>>st;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vector<pair<int, int>>vec;
                if(!vis[i][j] && grid[i][j] == 1) {
                    dfs(grid, i, j, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

/*Time: O(N * M) , Space: O(N * M) */

int main() {
    vector<vector<int>>grid = {
        {1, 1, 0, 1, 1}, {1, 0, 0, 0, 0}, {0, 0, 0, 0, 1},{1, 1, 0, 1, 1}
    };

    Solution sol;
    cout << "Number of Distinct Islands is: " << sol.countDistinctIslands(grid) << endl;
    return 0;
}