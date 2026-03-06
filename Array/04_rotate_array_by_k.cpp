#include <iostream>
using namespace std;

void rotateByOne(int arr[], int n){
    // [1, 3, 2, 5, 9, 7]
    int temp = arr[0];
    for(int i = 1; i < n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}
void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverse(int arr[], int start, int end){
    while(start <= end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
int main(){
    int n = 6;
    int k = 20;
    int arr[n] = {1, 3, 2, 5, 9, 7};
    int d = k % n;
    cout << "d = " << d << endl;
    print(arr, n);
    // rotateByOne(arr, n);
    // reverse(arr, 0, d-1); 
    // reverse(arr, d, n-1);
    // reverse(arr, 0, n-1);

    reverse(arr, 0, n-d-1);
    reverse(arr, n-d, n-1);
    reverse(arr, 0, n-1);
    print(arr, n);

    return 0;
}