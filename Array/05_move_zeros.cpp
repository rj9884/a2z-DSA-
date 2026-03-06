#include <iostream>
using namespace std;

void moveZeros(int arr[], int n){
    int j = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    if(j == -1){
        cout << "No zero in given array\n";
        return;
    }
    for(int i = j+1; i < n; i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    // 2, 3, 0, 4, 5, 0, 0, 7, 8
    int n = 9;
    int arr[n] = {2, 3, 0, 4, 5, 0, 0, 7, 8};
    print(arr, n);
    moveZeros(arr, n);
    print(arr, n);

    return 0;
}