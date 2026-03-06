#include <iostream>

using namespace std;


/*  1. goes to each index from 0 to n-1
    2. for each element move it to correct position by swapping as left as possible 

*/
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void insertionSOrt(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
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
    int n = 6;
    int arr[n] = {2,6, 23,1, 3, 76};

    print(arr, n);
    insertionSOrt(arr, n);
    print(arr, n);

    return 0;
}