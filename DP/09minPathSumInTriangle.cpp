#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // Recursion
    int move(int i, int j, vector<vector<int>>& triangle, int n) {
        if(i == n-1) return triangle[n-1][j];
        
        int d = triangle[i][j] + move(i+1, j, triangle, n);
        int dg = triangle[i][j] + move(i+1, j+1, triangle, n);

        return min(d, dg);
    }
    // memoization
    int move(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>&dp) {
        if(i == n-1) return triangle[n-1][j];
        if(dp[i][j] != -1) return dp[i][j];
    
        int d = triangle[i][j] + move(i+1, j, triangle, n, dp);
        int dg = triangle[i][j] + move(i+1, j+1, triangle, n, dp);
    
        return dp[i][j] = min(d, dg);
    }
    int tabulation(vector<vector<int>>& triangle, int n) {
            vector<vector<int>>dp(n, vector<int>(n, 0));
            for(int j = 0; j < n; j++) {
                dp[n-1][j] = triangle[n-1][j];
            }
            for(int i = n-2; i >= 0; i--) {
                for(int j = i; j >= 0; j--) {
                    int d =  triangle[i][j] + dp[i+1][j];
                    int dg = triangle[i][j] + dp[i+1][j+1];
    
                    dp[i][j] = min(d, dg);
                }
            }
            return dp[0][0];
        }
       // Space Optimization
       int spaceOptimization(vector<vector<int>>& triangle, int n) {
               vector<int>curr(n, 0), front(n, 0);
               for(int j = 0; j < n; j++) {
                   front[j] = triangle[n-1][j];
               }
               for(int i = n-2; i >= 0; i--) {
                   for(int j = i; j >= 0; j--) {
                       int d =  triangle[i][j] + front[j];
                       int dg = triangle[i][j] + front[j+1];
       
                       curr[j] = min(d, dg);
                   }
                   front = curr;
               }
               return front[0];
           } 
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        // return move(0, 0, triangle, n);
        
        // return move(0, 0, triangle, n, dp);
        // return tabulation(triangle, n);
        return spaceOptimization(triangle, n);
    }
};

int main() {
    vector<vector<int>>triangle = {
        {2},{3,4},{6,5,7},{4,1,8,3}
    };
    Solution sol;
    cout << "Min path sum = " << sol.minimumTotal(triangle) << endl;

    return 0;
}