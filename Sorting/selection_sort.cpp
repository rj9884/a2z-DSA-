#include <iostream>

using namespace std;


/*  swap at idx 0, {min indx [0 - n-1]}
    swap at idx 1, {min indx [1 - n-1]}
    swap at idx 2, {min indx [2 - n-1]}

*/
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n){
    for(int i = 0; i < n-2; i++){
        int minIndex = i;
        for(int j = i; j < n-1; j++){
            if(arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
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
    selectionSort(arr, n);
    print(arr, n);

    return 0;
}