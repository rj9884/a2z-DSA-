#include <iostream>

using namespace std;

/*
- brute apprach ---> Using merge sort (O(nlog(n)) and space - O(n) extra array)
- better sol. Using three count pointer and iterating through loop once then overriding existing values
- optimal --> Dutch National Flag Algorithm
*/

/*
Dutch National Flag Algorithm
[0 .......low-1] ---> 0  (extreme left)
[low ......mid-1] ----> 1
[high+1 ......n-1] ----> 2  (extreme right)
*/

void sortArraysOfZeroOnesAndTwo(int arr[], int n){
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }else if(arr[mid] == 1){
            mid++;
        }else{
            swap(arr[mid], arr[high]);
            high--;

        }
    }
}

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n = 10;
    int arr[n] = {1,0,0,1,0,2,1,2,0,1};
    print(arr, n);
    sortArraysOfZeroOnesAndTwo(arr, n);
    print(arr, n);
    return 0;
}