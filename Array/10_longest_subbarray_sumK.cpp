#include <iostream>
#include <map>
using namespace std;

int longestSubArraySumUsingTwoPointers(int arr[], int n, int k);
int longestSubarrayWithSumK(int arr[], int n, int k){
    map<int, int>preSumMap;
    int sum = 0;
    int maxLen = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        int rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
    }
    return maxLen;

}

int main(){
    int n = 7;
    int k = 3;
    int arr[] = {1, 2, 3, 1, 1, 1, 1};
    //cout << longestSubarrayWithSumK(arr, n, k) << endl;
    cout << longestSubArraySumUsingTwoPointers(arr, n, k) << endl;
    
    return 0;
}


int longestSubArraySumUsingTwoPointers(int arr[], int n, int k){
    int left = 0;
    int right = 0;
    int sum = arr[0];
    int maxLen = 0;

    while(right < n){
        while(left <= right && sum > k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right - left +1);
        }
        right++;
        if(right < n) sum += arr[right];
        
    }
    return maxLen;
}