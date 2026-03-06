#include <iostream>
#include <unordered_map>
using namespace std;
int findUsingHash(int arr[], int n);
int findUsingXOR(int arr[], int n);

int main(){
    int n = 9;
    int arr[n] = {1, 1, 2, 3, 3, 2, 4, 5, 5};

    cout << findUsingHash(arr, n) << endl;
     cout << findUsingXOR(arr, n) << endl;
    return 0;
}

// 1, 1, 2, 3, 3, 4, 4, 5, 5
int findUsingHash(int arr[], int n){
    unordered_map<int, int>map;

    for(int i = 0; i < n; i++){
        map[arr[i]]++;
    }
    for(auto it : map){
        if(it.second == 1) return it.first;
    }
    return -1;
}

// using XOR

int findUsingXOR(int arr[], int n){
    int xor1 = 0;
    for(int i = 0; i < n; i++){
        xor1 = xor1 ^ arr[i];
    }
    return xor1;
}