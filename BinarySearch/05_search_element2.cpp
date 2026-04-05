#include <iostream>
#include <vector>

using namespace std;
int searchRotated(vector<int>&nums, int target);

int main() {
    vector<int>arr = {4,5,6,6,7,0,1,2,4,4};
    cout << searchRotated(arr, 4) << endl;
    return 0;
}

// Duplicates allowed
int searchRotated(vector<int>&nums, int target) {
    int n = nums.size();
    int low =  0;
    int high = n-1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) return 1;
        if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue;
        }
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
    return 0;
}