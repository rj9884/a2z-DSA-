#include <iostream>
#include <vector>

using namespace std;

// variable starting and ending point
class Solution {
private:
    // Recursion
    /*Time: O(3^n * m) , Space: O(N) --> recursion stack space */
    int getMinPath(int i, int j, vector<vector<int>>&matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(j < 0 || j >= m) return 1e9;
        if(i == 0) return matrix[0][j];

           
        int up = matrix[i][j] + getMinPath(i-1, j, matrix);
        int ld = matrix[i][j];
        if(j >= 0) ld += getMinPath(i-1, j-1, matrix);
        int rd = matrix[i][j];
        if(j < m) rd += getMinPath(i-1, j+1, matrix);

        return min(up, min(ld, rd));
        return 0;
    }
    /*Time: O(n * m), Space: O(n * m) + recursion stack */
    int memoization(int i, int j, vector<vector<int>>&matrix, vector<vector<int>>&dp) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(j < 0 || j >= m) return 1e9;
        if(i == 0) return matrix[0][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = matrix[i][j] + memoization(i-1, j, matrix, dp);
        int ld = matrix[i][j];
        if(j >= 0) ld += memoization(i-1, j-1, matrix, dp);
        int rd = matrix[i][j];
        if(j < m) rd += memoization(i-1, j+1, matrix, dp);
        
        return dp[i][j] = min(up, min(ld, rd));
    }
    /*Time: O(n * m), Space: O(n * m) */
    int tabulation(vector<vector<int>>&matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int up = matrix[i][j] + dp[i-1][j];
                int ld = matrix[i][j];
                if(j > 0) ld += dp[i-1][j-1];
                else ld += 1e8;
                int rd = matrix[i][j];
                if(j < m-1) rd += dp[i-1][j+1];
                else rd += 1e8;
                
                dp[i][j] = min(up, min(ld, rd));
            }
        }
        int mini = 1e9;
        for(int j = 0; j < m; j++) {
            mini = min(mini, dp[n-1][j]);
        }
        return mini;
    }
    // Space Optimization
    int spaceOptimization(vector<vector<int>>&matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>prev(m, 0), curr(m, 0);
        for(int j = 0; j < m; j++) {
            prev[j] = matrix[0][j];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int up = matrix[i][j] + prev[j];
                int ld = matrix[i][j];
                if(j > 0) ld += prev[j-1];
                else ld += 1e8;
                int rd = matrix[i][j];
                if(j < m-1) rd += prev[j+1];
                else rd += 1e8;
                
                curr[j] = min(up, min(ld, rd));
            }
            prev = curr;
        }
        int mini = 1e9;
        for(int j = 0; j < m; j++) {
            mini = min(mini, prev[j]);
        }
        return mini;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        int mini = 1e9;
        //for(int j = 0; j < m; j++) {
        //    // mini = min(mini, getMinPath(n-1, j, matrix));
        //    mini = min(mini, memoization(n-1, j, matrix, dp));
        //}
        //return mini;
        // return tabulation(matrix);
        return spaceOptimization(matrix);
    }
};

int main() {
    
    vector<vector<int>>matrix = {
       {2,1,3},{6,5,4},{7,8,9}
    };
    Solution sol;
    cout << "Minimum fallingPathSum is: " << sol.minFallingPathSum(matrix) << endl;
    return 0;
}