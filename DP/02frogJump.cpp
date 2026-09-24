#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    // Time: O(N) , Space: O(N)
    int solveMemoization(int index, vector<int>& height, vector<int>& dp) {
        if (index == 0)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int oneStep = solveMemoization(index - 1, height, dp)
                    + abs(height[index] - height[index - 1]);

        int twoStep = 1e9;

        if (index > 1)
            twoStep = solveMemoization(index - 2, height, dp)
                    + abs(height[index] - height[index - 2]);

        return dp[index] = min(oneStep, twoStep);
    }

public:
    int frogJumpMemoization(int n, vector<int>& height) {
        vector<int> dp(n, -1);
        return solveMemoization(n - 1, height, dp);
    }
    // Time; O(N) , Space: O(1)
    int frogJumpTabulation(int n, vector<int>& height) {
        int previous = 0;
        int previousTwo = 0;

        for (int i = 1; i < n; i++) {
            int oneStep = previous
                        + abs(height[i] - height[i - 1]);

            int twoStep = 1e9;

            if (i > 1)
                twoStep = previousTwo
                        + abs(height[i] - height[i - 2]);

            int current = min(oneStep, twoStep);

            previousTwo = previous;
            previous = current;
        }

        return previous;
    }
};

int main() {
    int n = 5;

    vector<int> height = {2, 1, 3, 5, 4};

    Solution solution;

    cout << "Minimum Energy Using Memoization = "
         << solution.frogJumpMemoization(n, height) << endl;

    cout << "Minimum Energy Using Tabulation = "
         << solution.frogJumpTabulation(n, height) << endl;

    return 0;
}