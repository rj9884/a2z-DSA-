#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int minPath(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp) {
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];

        int up = grid[i][j];
        if(i > 0) up += minPath(i-1, j, grid, dp);
        else up = 1e9;
        int left = grid[i][j];
        if(j > 0) left += minPath(i, j-1, grid, dp);
        else left = 1e9;

        dp[i][j] =  min(up, left);
        return dp[i][j];
    }
    int tabulation(int m, int n, vector<vector<int>>&grid) {
        vector<vector<int>>dp(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) dp[i][j] = grid[0][0];
                else {
                    int up = grid[i][j];
                    if(i > 0) up += dp[i-1][j];
                    else up = 1e9;

                    int left = grid[i][j];
                    if(j > 0) left += dp[i][j-1];
                    else left = 1e9;

                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n  = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));

        // return minPath(m-1, n-1, grid, dp);
        return tabulation(m, n, grid);
    }
};

int main() {
    vector<vector<int>>grid = {
        {1,3,1},{1,5,1},{4,2,1}
    };
    Solution sol;
    cout << "Minimum Path Sum is: " << sol.minPathSum(grid) << endl;
    return 0;
}