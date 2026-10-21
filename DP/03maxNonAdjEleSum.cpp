#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    private:
        // memoization
        /* Time: O(N) , Space: (N) + (N) */
        int f(int idx, vector<int> &nums, vector<int>&dp) {
            if(idx == 0) return nums[idx];
            if(idx < 0) return 0;
            if(dp[idx] != -1) return dp[idx];

            int pick = nums[idx] + f(idx-2, nums, dp);
            int notPick = 0 + f(idx-1, nums, dp);

            return dp[idx] = max(pick, notPick);
        }
        // tabulation
        // Time: O(N) , Space: O(N)
    public:
        int tabulation(vector<int>&nums, vector<int>&dp) {
            int n = nums.size();
            if(n == 0) return 0;
           dp[0] = nums[0];
           for(int i = 1; i < n; i++) {
               int pick = nums[i];
               if(i > 1) pick += dp[i-2];
               int notPick = 0 + dp[i-1];
               dp[i] = max(pick, notPick);
           }
           return dp[n-1];
       }
       // Time : O(N) , Space: O(1)
       int spaceOptimization(vector<int>&nums) {
           int n = nums.size();
           if(n == 0) return 0;
           int prev = nums[0];
           int prev2 = 0;

           for(int i = 1; i < n; i++) {
               int pick = nums[i];
               if(i > 1) pick += prev2;
               int notPick = prev;
               int curr = max(pick, notPick);
               prev2 = prev;
               prev = curr;
           }
           return prev;
       }  
    public:
        int maxNonAdjSum(vector<int>nums) {
            int n = nums.size();
            if(n == 0) return 0;
            vector<int>dp(n, -1);
            return f(n -1, nums, dp);
        } 
};


int main() {
    vector<int>nums = {2, 1, 4, 9};
    Solution sol;
    int n = nums.size();
    vector<int>dp(n, -1);
    cout << "Maximum Sum of non adjacent elements (Memoization): " <<  sol.maxNonAdjSum(nums) << endl;
    cout << "Maximum Sum of non adjacent elements (tabulation): " <<  sol.tabulation(nums, dp) << endl;
    cout << "Maximum Sum of non adjacent elements (Space Optimization): " <<  sol.spaceOptimization(nums) << endl;
    return 0;
}

