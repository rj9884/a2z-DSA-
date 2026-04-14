#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;
int findMax(vector<int>&nums);
int sumDivisiorbyD(vector<int>&arr, int d);
int smallestDivisor(vector<int>&nums, int threshold);

int main() {
    vector<int>arr = {1,2,5,9};
    cout << smallestDivisor(arr,6 );
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

int sumDivisiorbyD(vector<int>&arr, int d) {
    int n = arr.size();
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += ceil((double)arr[i] / (double)d);
    }
    return sum;
}


int smallestDivisor(vector<int>&nums, int threshold) {
    int n = nums.size();
    int low = 1;
    int high = findMax(nums);

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(sumDivisiorbyD(nums, mid) <= threshold ) high = mid-1;
        else low = mid+1;
    }
    return low;
}
