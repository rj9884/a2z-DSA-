// Swap an Array
#include <iostream>

using namespace std;

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int &i, int &j){
    int temp = i;
    i = j;
    j = temp;
}

void funSwap2Pointer(int arr[], int l, int r){
    if(l >= r){
        return;
    }
    swap(arr[l], arr[r]);
    funSwap2Pointer(arr, l+1, r-1);
}

void funSwap1Pointer(int arr[], int i, int n){
    if(i >= n/2) return;

    swap(arr[i], arr[n-i-1]);
    funSwap1Pointer(arr, i+1, n);
}

int main(){
    int n = 5;
    int arr[n] = {1, 4, 5, 7, 2};
    print(arr, n);
    cout << endl;
    int l = 0;
    int r = n-1;
    // funSwap2Pointer(arr, l, r);
    funSwap1Pointer(arr, 0, n);
    cout << endl;
    print(arr, n);
    return 0;
}