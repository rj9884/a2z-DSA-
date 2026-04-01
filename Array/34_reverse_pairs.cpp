#include <iostream>
#include <vector>

using namespace std;
int reversePairsBrute(vector<int>&nums);
void merge(vector<int>& arr, int low, int mid, int high);
int mergeSort(vector<int>& arr, int low, int high);
int countPairs(vector<int>&arr, int low, int mid, int high);
int reversePairsOptimal(vector<int>&nums);

int main() {
    vector<int>arr = {40,25,19,12,9,6,2};
    cout << reversePairsBrute(arr) << endl;
    cout << reversePairsOptimal(arr) << endl;
    return 0;
}


// Brute
/* a[i] > 2* a[j]

*/
int reversePairsBrute(vector<int>&nums) {
    int n = nums.size();
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(nums[i] > 2* nums[j]) cnt++;
        }
    }
    return cnt;
}


// optimal
// time : O(2nlogn) , space O(n)
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else {
            temp.push_back(arr[right++]);
        }            
    }

    while (left <= mid)
        temp.push_back(arr[left++]);

    while (right <= high)
        temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

int mergeSort(vector<int>& arr, int low, int high) {
    int cnt = 0;
    if (low >= high)
        return cnt;

    int mid = (low + high) / 2;

    cnt += mergeSort(arr, low, mid);

    cnt += mergeSort(arr, mid + 1, high);
    cnt += countPairs(arr, low, mid, high);

    merge(arr, low, mid, high);
    return cnt;
}
int countPairs(vector<int>&arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;

    for(int i = low; i <= mid; i++) {
        while(right <= high && arr[i] > 2 * arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}


int reversePairsOptimal(vector<int>&nums) {
    int n = nums.size();
    return mergeSort(nums, 0, n-1);
}