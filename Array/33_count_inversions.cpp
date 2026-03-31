#include <iostream>
#include <vector>

using namespace std;
int countInversionBrute(vector<int>&nums);
int merge(vector<int>& arr, int low, int mid, int high);
int mergeSort(vector<int>& arr, int low, int high);
int countInversionOptimal(vector<int>&nums);

int main() {
    vector<int>arr = {5,3,2,1,4};
    cout << countInversionBrute(arr) << endl;
    cout << countInversionOptimal(arr) << endl;
    return 0;
}


// Brute

int countInversionBrute(vector<int>&nums) {
    int n = nums.size();
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(nums[i] > nums[j]) cnt++;
        }
    }
    return cnt;
}

// optimal
// time : O(nlogn) , space O
int merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;
    int cnt = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else {
            temp.push_back(arr[right++]);
            cnt += (mid - left + 1);
        }            
    }

    while (left <= mid)
        temp.push_back(arr[left++]);

    while (right <= high)
        temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
    return cnt;
}

int mergeSort(vector<int>& arr, int low, int high) {
    int cnt = 0;
    if (low >= high)
        return cnt;

    int mid = (low + high) / 2;

    cnt += mergeSort(arr, low, mid);

    cnt += mergeSort(arr, mid + 1, high);

    cnt += merge(arr, low, mid, high);
    return cnt;
}

int countInversionOptimal(vector<int>&nums) {
    int n = nums.size();
    return mergeSort(nums, 0, n-1);
}