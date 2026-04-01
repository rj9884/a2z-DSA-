#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int maxProductSubarrayBrute(vector<int>&nums);
int maxProductSubarrayBetter(vector<int>&nums);
int maxProductSubarrayOptimal(vector<int>&nums);

int main() {
    vector<int>arr = {2, 3, -2, 4};
    cout << maxProductSubarrayBrute(arr) << endl;
    cout << maxProductSubarrayBetter(arr) << endl;
    cout << maxProductSubarrayOptimal(arr) << endl;
    return 0;
}

/* Brute
   time : O(N^3)  , space : O(1) */
int maxProductSubarrayBrute(vector<int>&nums) {
    int n = nums.size();
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int prod = 1;
            for(int k = i; k <= j; k++) {
                prod *= nums[k];
            }
            maxi = max(maxi, prod);
        }
    }
    return maxi;
}

/* Better
   time : O(N^2)  , space : O(1) */


int maxProductSubarrayBetter(vector<int>&nums) {
    int n = nums.size();
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++) {
        int prod = 1;
        for(int j = i; j < n; j++) {
            prod *= nums[j];
            maxi = max(maxi, prod);
        }  
    }
    return maxi;
}

/* Optimal
   time : O(N) , space : O(1)*/

int maxProductSubarrayOptimal(vector<int>&nums) {
    int n = nums.size();
    int pre = 1;
    int suff = 1;
    int ans = INT_MIN;

    for(int i = 0; i < n; i++) {
        if(pre == 0) pre = 1;
        if(suff == 0) suff = 1;

        pre *= nums[i];
        suff *= nums[n-i-1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}