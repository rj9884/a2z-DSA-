#include <iostream>
#include <vector>

using namespace std;
vector<int> firstAndLastOccurence(vector<int>&nums, int target);
int upper_bound(vector<int>&nums, int target);
int lower_bound(vector<int>&nums, int target);
vector<int> firstAndLastOccurenceOptimal(vector<int>&nums, int target);
vector<int> searchRange(vector<int>& nums, int target);

int main() {
    vector<int>arr = {2,4,6,8,8,8,11,13};
    // vector<int>ans = firstAndLastOccurence(arr, 8);
    vector<int>ans = firstAndLastOccurenceOptimal(arr, 8);
    
    for(auto val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}


// brute 
vector<int> firstAndLastOccurence(vector<int>&nums, int target) {
    int n = nums.size();
    int first = -1;
    int last = -1;

    for(int i = 0; i < n; i++) {
        if(nums[i] == target) {
            if(first == -1) first = i;
            last = i;
        }
    }
    return {first, last};
}

// Optimal using lower_bound & upper_bound

int lower_bound(vector<int>&nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = n;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }else {
            low = mid+1;
        }
    }
    return ans;
}

int upper_bound(vector<int>&nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = n;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] > target) {
            ans = mid;
            high = mid - 1;
        }else {
            low = mid+1;
        }
    }
    return ans;
}

vector<int> firstAndLastOccurenceOptimal(vector<int>&nums, int target) {
    int n = nums.size();
    int lb = lower_bound(nums, target);

    if(lb == n || nums[lb] != target) return {-1, -1};

    return {lb, (upper_bound(nums, target) - 1)};
}

// single binary search 
vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0; 
        int high = n-1;
        int first = -1, last = -1;

        // first occurence
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target) {
                if(nums[mid] == target) {
                    first = mid;
                }
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        // second occurence
        low = 0;
        high = n-1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] <= target) {
                if(nums[mid] == target) {
                    last = mid;
                }
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        return {first, last};
    }