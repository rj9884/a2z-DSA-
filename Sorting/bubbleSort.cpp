#include <iostream>

using namespace std;


/*  0 - [n-1]
    0 - [n-2]
    0 - [n-3]
    Adjacent swapping -> largest element at the end after each 

*/
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n){
    for(int i = n-1; i >= 1; i--){
        int didSwap = 0;
        for(int j = 0; j <= i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                didSwap = 1;
            }
        }
        if(didSwap == 0) break;
    }
}

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int n = 6;
    int arr[n] = {2,6, 23,1, 3, 76};

    print(arr, n);
    bubbleSort(arr, n);
    print(arr, n);

    return 0;
}