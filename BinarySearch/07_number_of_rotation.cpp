#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int numberOfRotation(vector<int>&nums);

int main() {
    vector<int>arr = {5,6,7,1,2,3,4};
    cout << numberOfRotation(arr) << endl;
    return 0;
}

int numberOfRotation(vector<int>&nums) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    int idx = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(nums[low] <= nums[high]) {  // optimisation
            if(nums[low] < ans ) {
                idx = low;
                ans = nums[low];
            }
            break;
        }

        if(nums[low] <= nums[mid]) {
            if(nums[low] < ans ) {
                idx = low;
                ans = nums[low];
            }
            low = mid+1;
        }else{
            if(nums[mid] < ans ) {
                idx = mid;
                ans = nums[mid];
            }
            high = mid-1;
        }
    }
    return idx;
}