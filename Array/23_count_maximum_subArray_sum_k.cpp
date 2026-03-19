#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countMaximumSubArraySumBrute(vector<int>arr, int k);
int countMaximumSubArraySumBetter(vector<int>arr, int k);
int findAllSubarraysWithGivenSumOptimal(vector<int>arr, int k);
int main() {
    vector<int>arr = {1,2,3,-3,1,1,1,4,2,-3};
    // cout << countMaximumSubArraySumBrute(arr, 3);
    // cout << countMaximumSubArraySumBetter(arr, 3);
    cout << findAllSubarraysWithGivenSumOptimal(arr, 3);
    return 0;
}


// brute Force time : O(n^3)

int countMaximumSubArraySumBrute(vector<int>arr, int k) {
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum  += arr[k];
            }
            if (sum == k) count++;
        }
    }
    return count;
}

// better time : O(n^2)

int countMaximumSubArraySumBetter(vector<int>arr, int k) {
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == k) count++;
        }
    }
    return count;
}

// Optimal time : O(nlog(n)) || O(n*(O(1))) , space : O(n) , using prefix sum

int findAllSubarraysWithGivenSumOptimal(vector<int>arr, int k) {
    int n = arr.size();
    unordered_map<int, int>mpp;
    mpp[0] = 1;
    int cnt = 0;
    int preSum = 0;
    for (int i = 0; i < n; i++) {
        preSum += arr[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }
    return cnt;
}