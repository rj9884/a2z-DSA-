#include <iostream>
#include <vector>
#include <climits>
#include <cmath>


using namespace std;
int possible(vector<int>&arr, int days, int m, int k);
int findMax(vector<int>&nums);
int findMin(vector<int>&nums);
int roseGarden(vector<int>&nums, int m, int k);

int main() {
    vector<int>arr = {1,10, 3, 10, 2};
    cout << roseGarden(arr, 3, 1);
    return 0;
}

int possible(vector<int>&arr, int days, int m, int k) {
    int n = arr.size();
    int cnt = 0;
    int noOfB = 0;
    

    for(int i = 0; i < n; i++) {
        if(arr[i] <= days) {
            cnt++;
        }
        else {
            noOfB += cnt / k;
            cnt = 0;
        }
    }
    noOfB += cnt / k;
    return noOfB >= m;
}

int findMax(vector<int>&nums) {
    int n = nums.size();
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++) {
        maxi = max(maxi, nums[i]);
    }
    return maxi;
}
int findMin(vector<int>&nums) {
    int n = nums.size();
    int mini = INT_MAX;

    for(int i = 0; i < n; i++) {
        mini = min(mini, nums[i]);
    }
    return mini;
}

int roseGarden(vector<int>&nums, int m, int k) {
    int n = nums.size();
    long long val = m * 1LL * k * 1LL;
    if(val > n) return -1;
    int low = findMin(nums);
    int high = findMax(nums);

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(possible(nums, mid, m, k)) high = mid-1;
        else low = mid+1;
    }
    return low;
}