#include <iostream>
#include <climits>
using namespace std;
int largestElement(int arr[], int n);
int secondLargest(int arr[], int n);
int secondLargestOpt(int arr[], int n);
int secondSmallest(int arr[], int n);
int main(){
    int n = 6;
    int arr[n] = {23, 1 , 78, 24, 56, 12};
    printf("%d is largest\n",largestElement(arr, n));
    printf("%d is second largest\n",secondLargest(arr, n));
    printf("%d is second largest OPT\n",secondLargestOpt(arr, n));
    printf("%d is second smallest\n",secondSmallest(arr, n));
}

// Brute Force

int largestElement(int arr[], int n){
    int largest = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > largest) largest = arr[i];
    }
    return largest;
}

int secondLargest(int arr[], int n){
    int sLargest = -1;
    int largest = largestElement(arr, n);
    for(int i = 0; i < n; i++){
        if(arr[i] > sLargest && arr[i] != largest){
            sLargest = arr[i];
        }
    }
    return sLargest;
}

// optimized sol

int secondLargestOpt(int arr[], int n){
    int largest = arr[0];
    int sLargest = -1;

    for(int i = 1; i < n; i++){
        if(arr[i] > largest){
            sLargest = largest;
            largest = arr[i];
        }else if(arr[i] < largest && arr[i] > sLargest){
            sLargest = arr[i];
        }
    }
    return sLargest;
}


// second Smallest

int secondSmallest(int arr[], int n){
    int smallest = arr[0];
    int sSmallest = INT_MAX;

    for(int i = 1; i < n; i++){
        if(arr[i] < smallest){
            sSmallest = smallest;
            smallest = arr[i];
        }else if(arr[i] != smallest && arr[i] < sSmallest){
            sSmallest = arr[i];
        }
    }
    return sSmallest;
}