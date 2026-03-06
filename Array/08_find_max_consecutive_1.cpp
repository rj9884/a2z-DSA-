#include <iostream>
using namespace std;

int maxConsecutiveOne(int arr[], int n){
    int maximum = 0;
    int cnt = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            cnt++;
            maximum = max(maximum, cnt);
        }else{
            cnt = 0;
        }
    }
    return maximum;
}
int main(){
    int n = 12;
    int arr[n] = {1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0};
    cout << "Maximum ones are: " << maxConsecutiveOne(arr, n) << endl;
    return 0;
}