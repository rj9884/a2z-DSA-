#include <iostream>
#include <vector>

using namespace std;
int searchRotated(vector<int>&nums, int target);

int main() {
    vector<int>arr = {7,8,9,1,3,5,6};
    cout << searchRotated(arr, 1) << endl;
    return 0;
}

int searchRotated(vector<int>&nums, int target) {
    int n = nums.size();
    int low =  0;
    int high = n-1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) return mid;
        if(nums[low] <= nums[mid]) {
            if(nums[low] <= target && target <= nums[mid]) {
                high = mid-1;
            }else {
                low = mid+1;
            }

        }else {
            if(nums[mid] <= target && target <= nums[high]) {
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }
    return -1;
}