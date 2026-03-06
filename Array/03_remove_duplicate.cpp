#include <iostream>
using namespace std;

int removeDuplicate(int arr[], int n){
    int i = 0;
    for(int j = 1; j < n; j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}
int main(){
    int n = 9;
    int arr[n] = {1,1,2,2,2,3,3,4,4};
    printf("%d\n", removeDuplicate(arr, n));
    return 0;
}