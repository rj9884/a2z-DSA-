#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int>arr);
vector<int> nextPermutation(vector<int> nums);

int main(){
    vector<int>arr = {2,3,5,4,1,0,0};
    vector<int>vec1 = {1,3,2};
    // printVector(arr);
    printVector(vec1);
    // vector<int>arr1 = nextPermutation(arr);
    vector<int>arr1 = nextPermutation(vec1);
    
    printVector(arr1);
    return 0;
}

vector<int> nextPermutation(vector<int> nums){
    int n = nums.size();
    int idx = -1;

    for(int i = n-2; i >= 0; i--){
        if(nums[i] < nums[i+1]){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        reverse(nums.begin(), nums.end());
        return nums;
    }

    for(int i = n-1; i > idx; i--){
        if(nums[i] > nums[idx]){
            swap(nums[i], nums[idx]);
            break;
        }
    }
    reverse(nums.begin() + idx+1, nums.end());

    return nums;
}


void printVector(vector<int>arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
