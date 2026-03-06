#include <iostream>
#include <climits>
using namespace std;

bool isSorted(int arr[], int n){
    for(int i = 1; i < n; i++){
        if(arr[i] >= arr[i-1]){

        }else{
            return false;
        }
    }
    return true;
}
int main(){
    int n = 6;
    // int arr[n] = {23, 1 , 78, 24, 56, 12};
    int arr[n] = {1, 23, 34, 34, 45, 57};

    printf("%d\n", isSorted(arr, n));
    return 0;
}

