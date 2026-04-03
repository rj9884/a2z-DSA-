#include <iostream>
#include <vector>

using namespace std;
int lowerBound(vector<int>&nums , int x);
int upperBound(vector<int>&nums , int x);
int searchInsert(vector<int>&nums , int x);
int floor(vector<int>&nums , int x);
int ceil(vector<int>&nums , int x);

int main() {
    vector<int> arr = {1,2,3,3,5,8,8,10,10,11};
    cout << lowerBound(arr, 5) << endl;
     cout << upperBound(arr, 5);
    return 0;
}


int lowerBound(vector<int>&nums , int x) {
    int n = nums.size();
    int ans = n;
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return ans;
}


// Upper Bound

int upperBound(vector<int>&nums , int x) {
    int n = nums.size();
    int ans = n;
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] > x) {
            ans = mid;
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return ans;
}

// search insert : finding lower bound for insertion at correct position

int searchInsert(vector<int>&nums , int x) {
    int n = nums.size();
    int ans = n;
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return ans;
}

// floor
int floor(vector<int>&nums , int x) {
    int n = nums.size();
    int ans = -1;
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] <= x) {
            ans = nums[mid];
            low = mid + 1;
            
        }else {
            high = mid - 1;
        }
    }
    return ans;
}

// ceil

int ceil(vector<int>&nums , int x) {
    int n = nums.size();
    int ans = -1;
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] > x) {
            ans = nums[mid];
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return ans;
}