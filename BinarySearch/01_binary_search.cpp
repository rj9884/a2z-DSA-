#include <iostream>
#include <vector>

using namespace std;
int binarySearch(vector<int>&nums , int target);
int binarySearchRecursive(vector<int>&nums ,int low, int high, int target);

int main() {
    vector<int> arr = {3,4,6,7,9,12,16,17};
    int n = arr.size();
    cout << binarySearch(arr, 6) << endl;
    cout << binarySearchRecursive(arr, 0, n-1, 12);
    return 0;
}

int binarySearch(vector<int>&nums , int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = low + ((high - low) / 2);
        if(nums[mid] == target) return mid;
        else if(target > nums[mid]) low = mid + 1;
        else {
            high = mid - 1;
        }
    }
    return -1;
}

// Recursive

int binarySearchRecursive(vector<int>&nums ,int low, int high, int target) {
    if(low > high) return -1;
    
    int mid = low + ((high - low) / 2);
    if(nums[mid] == target) return mid;

    else if(target > nums[mid]) {
        return binarySearchRecursive(nums, mid+1, high, target );
    }
    else {
        return binarySearchRecursive(nums, low, mid-1, target);
    }
}