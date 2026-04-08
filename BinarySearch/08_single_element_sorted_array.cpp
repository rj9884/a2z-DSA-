#include <iostream>
#include <vector>

using namespace std;
int singleNonDuplicate(vector<int>&nums);

int main() {
    vector<int>arr = {1,1,2,2,3,3,4,5,5,6,6};
    cout << singleNonDuplicate(arr) << endl;
    return 0;
}

int singleNonDuplicate(vector<int>&nums) {
    int n = nums.size();

    if(nums[0] != nums[1]) return nums[0];
    if(nums[n-1] != nums[n-2]) return nums[n-1];

    int low = 1;
    int high = n-2;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
        // Element on left
        if(mid % 2 == 1 && nums[mid] == nums[mid-1]
         || mid % 2 == 1 && nums[mid] == nums[mid-1]) {
            low = mid + 1;
        }
        // Element is on right
        else {
            high = mid-1;
        }
    }
    return -1;
}