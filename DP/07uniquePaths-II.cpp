#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    /*Time: O(m×n), Space: O(m×n) + O(m×n) */
    int pathsCount(int i, int j, vector<vector<int>>&dp, vector<vector<int>>& obstacleGrid) {
        if(i == 0 && j == 0 && obstacleGrid[i][j] != 1 ) return 1;
        if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int left = pathsCount(i, j-1, dp, obstacleGrid);
        int up = pathsCount(i-1, j, dp, obstacleGrid);
        dp[i][j] = left + up;

        return dp[i][j];
    }
    /* Time: O(m×n), Space: O(m×n) */
    int tabulation(int row, int col, vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++ ) {
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 && j == 0 && obstacleGrid[i][j] != 1 ) dp[i][j] = 1;
                else {
                    int left = 0;
                    int up = 0;
                    if(j > 0) left = dp[i][j-1];
                    if(i > 0) up = dp[i-1][j];
                    dp[i][j] = left + up;
                }

            }
        }
        return dp[row-1][col-1];
        }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        // return pathsCount(m-1, n-1, dp, obstacleGrid);
        return tabulation(m, n, obstacleGrid);
    }
};

int main() {
    vector<vector<int>>obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    Solution sol;
    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}