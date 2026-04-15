#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int findMax(vector<int>&nums);
int findDays(vector<int>&weights , int cap);
int findSum(vector<int>&nums);
int leastWeightCapacity(vector<int>&weights , int day);

int main() {
    vector<int>arr = {1,2,3,4,5,6,7,8,9,10};
    cout << leastWeightCapacity(arr, 5) << endl;
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

int findDays(vector<int>&weights , int cap) {
    int n = weights.size();
    int days = 1;
    int load = 0;

    for(int i = 0; i < n; i++) {
        if(load + weights[i] > cap) {
            days += 1;
            load = weights[i];
        }
        else load += weights[i];
    }
    return days;
}

int findSum(vector<int>&nums) {
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += nums[i];
    }
    return sum;
}

/* time : log(sum(arr) - max(arr) + 1) * O(n)
   space : O(1)*/
int leastWeightCapacity(vector<int>&weights , int days) {
    // int low = *max_element(weights.begin(), weights.end());
    int low = findMax(weights);
    int high = findSum(weights);

    while(low <= high) {
        int mid = low + (high - low) / 2;
        int requiredDays = findDays(weights, mid);
        if(requiredDays <= days) high = mid-1;
        else low = mid+1;
    }
    return low;
}