#include <iostream>
#include <map>

using namespace std;

// better
string twoSum(int arr[], int n, int target){
    map<int , int>mpp;
    for(int i = 0; i < n; i++){
        int a = arr[i];
        int rem = target - a;

        if(mpp.find(rem) != mpp.end()){
            return "YES";  // return {mpp[rem], i}
        }
        mpp[a] = i;
    }
    return "NO";
}
// optimal : using two pointer

string twoSumPointer(int arr[], int n, int target){
    int left = 0;
    int right = n-1;

    // sort(arr.begin(), arr.end());

    while(left < right){
        int sum  = arr[left] + arr[right];

        if(sum == target){
            return "YES";
        }else if(sum < target){
            left++;
        }else{
            right++;
        }
    }
    return "NO";
}
int main(){
    int n = 5;
    int arr[n] = {4, 1, 2, 3, 1};

    cout << twoSum(arr, n, 5) << endl;
    return 0;
}