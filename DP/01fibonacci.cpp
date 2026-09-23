#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // time: O(N) , Space: O(1)
    int fib(int n) {
        if(n <= 0) return n;
        int prev2 = 0;
        int prev = 1;

        for(int i = 2; i <= n; i++) {
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    // time; O(N) , Space: O(N)
    int fib(int n, vector<int>&dp) {
        if(n <= 1) return n;

        if(dp[n] != -1) return dp[n];

        return dp[n] = fib(n-1, dp) + fib(n-2, dp);
    }
};


int main() {
    int n = 5;
    vector<int>dp(n+1, -1);
    Solution sol;
    cout << "fibonacci of " << n << " is: " << sol.fib(n, dp) << endl;
}