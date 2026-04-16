#include <iostream>
#include <vector>

using namespace std;
int missinNumber(vector<int>&nums, int k);

int main () {
    vector<int>arr = {2,3,4,7,11};
    cout << missinNumber(arr, 5) << endl;
    return 0;
}

int missinNumber(vector<int>&nums, int k) {
    int n = nums.size();
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        int missing = nums[mid] - (mid + 1);
        if(missing < k) low = mid+1;
        else high = mid-1;
    }
    return k + high + 1; // or low + k
}