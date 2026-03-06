#include <iostream>
#include <climits>

using namespace std;

// Kadane's Algorithm with indices
int maximumSubArraySumUsingKadane(int arr[], int n){
    int sum = 0;
    int maxSum = INT_MIN;

    int start = 0;
    int startIdx = 0;
    int endIdx = 0;

    for(int i = 0; i < n; i++){

        if(sum == 0)
            start = i;

        sum += arr[i];

        if(sum > maxSum){
            maxSum = sum;
            startIdx = start;
            endIdx = i;
        }

        if(sum < 0){
            sum = 0;
        }
    }

    cout << "StartIdx = " << startIdx << " EndIdx = " << endIdx << endl;
    return maxSum;
}

int main(){
    int n = 9;
    int arr[n] = {2, 1, -3, 4, -1, 2, 1, -5, 4};
    int arr2[5] = {5, 4, -1, 7, 8};

    cout << maximumSubArraySumUsingKadane(arr, n) << endl;
    cout << maximumSubArraySumUsingKadane(arr2, 5) << endl;

    return 0;
}