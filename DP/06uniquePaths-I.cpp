#include <iostream>
#include <vector>

using namespace std;

class Solution {
    private:
        /*Time: O(m×n), Space: O(m×n) + O(m×n) */

        int pathsCount(int i, int j, vector<vector<int>>&dp) {
           if(i == 0 && j == 0) return 1;
           if(i < 0 || j < 0) return 0;
           if(dp[i][j] != -1) return dp[i][j];
           int left = pathsCount(i, j-1, dp);
           int up = pathsCount(i-1, j, dp);
           dp[i][j] = left + up;

           return dp[i][j];
        }
    public:
        int uniquePaths(int m, int n) {
            vector<vector<int>>dp(m, vector<int>(n, -1));
            return pathsCount(m-1, n-1, dp);
        }
        /* Time: O(m×n), Space: O(m×n) */
        int tabulation(int row, int col) {
            vector<vector<int>> dp(row, vector<int>(col, 0));
            for(int i = 0; i < row; i++) {
                for(int j = 0; j < col; j++ ) {
                    if(i == 0 && j == 0) dp[i][j] = 1;
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
};

int main() {
    int m = 3, n = 7;

    Solution sol;
    cout << sol.uniquePaths(m, n) << endl;
    cout << sol.tabulation(m, n) << endl;


    return 0;
}
