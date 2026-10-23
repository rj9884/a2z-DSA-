#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    private:
        // memoization
        /* Time: O(N) , Space: O(N) + O(N * 4) */
        int maxPoints(int day, vector<vector<int>>&points, int last, vector<vector<int>>&dp) {
            if(dp[day][last] != -1) return dp[day][last];
            if(day == 0) {
                int best = 0;
                for(int activity = 0; activity < 3; activity++) {
                    if(activity != last) {
                        best = max(best, points[0][activity]);
                    }
                }
                dp[day][last] = best;
                return dp[day][last];
            }
            
            int best = 0;
            for(int activity = 0; activity < 3; activity++) {
                if(activity != last) {
                    int point = points[day][activity] + maxPoints(day-1, points, activity, dp);
                    best = max(best, point);
                }
            }
            dp[day][last] = best;
            return dp[day][last];
        }
    public:
        /* TIme: O(N) , Space: O(N)  */
        int tabulation(vector<vector<int>>&points) {
            int n = points.size();
            vector<vector<int>>dp(n, vector<int>(4, 0));
            dp[0][0] = max(points[0][1], points[0][2]);
            dp[0][1] = max(points[0][0], points[0][2]);
            dp[0][2] = max(points[0][0], points[0][1]);
            dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

            for(int day = 1; day < n; day++) {
                for(int last = 0; last < 4; last++) {
                    for(int activity = 0; activity < 3; activity++) {
                        if(activity != last) {
                            int point = points[day][activity] + dp[day-1][activity];
                            dp[day][last] = max(dp[day][last], point);
                        }
                    }
                } 
            }
            return dp[n-1][3];
        }
        /*Time : O(N), Space : O(1) */
        int spaceOptimization(vector<vector<int>>&points) {
            int n = points.size();
            int pre1=points[0][0],  pre2=points[0][1],  pre3=points[0][2];
            int cur1,  cur2,  cur3;
            for(int i=1; i<n; i++){
                cur1=points[i][0]+max(pre2,pre3);
                cur2=points[i][1]+max(pre3,pre1);
                cur3=points[i][2]+max(pre1,pre2);
                pre1=cur1;
                pre2=cur2;
                pre3=cur3;
            }
            return max(pre1,max(pre2,pre3));
        }
    
        int ninjaTraining(vector<vector<int>>& matrix) {
            int n = matrix.size();
            vector<vector<int>>dp(n, vector<int>(4, -1));
           return maxPoints(n-1, matrix, 3, dp);
           // return tabulation(matrix);
        }
};

int main() {
    vector<vector<int>>matrix =  {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };
    Solution sol;
    cout << "Max collected points is: " << sol.ninjaTraining(matrix) << endl;
    cout << "Max collected points is: " << sol.tabulation(matrix) << endl;
    cout << "Max collected points is: " << sol.spaceOptimization(matrix) << endl;
   
   return 0; 
}