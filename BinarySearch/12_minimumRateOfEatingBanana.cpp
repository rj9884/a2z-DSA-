#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;
int findMax(vector<int>&nums);
long long calculateTotalHours(vector<int>&nums , int hourly);
int minimumRateToEatBanana(vector<int>&nums , int h);

int main() {
    vector<int>arr = {3,6,2,8};
    cout << minimumRateToEatBanana(arr, 7) << endl;
    return 0;
}

int findMax(vector<int>&nums) {
    int n = nums.size();
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++) {
        maxi = max(maxi, nums[i]);
    }
    return maxi;
}

long long calculateTotalHours(vector<int>& nums, int hourly) {
    long long totalH = 0;
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        totalH += (nums[i] + hourly - 1) / hourly; // integer ceil
    }
    return totalH;
}

int minimumRateToEatBanana(vector<int>&nums , int h) {
    int low = 1;
    int high = findMax(nums);

    while(low <= high) {
        int mid = low + (high - low) / 2;
        long long requiredH = calculateTotalHours(nums, mid);

        if(requiredH <= h) high = mid-1;
        else low = mid+1;
    }
    return low;
}