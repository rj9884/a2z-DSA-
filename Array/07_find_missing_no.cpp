#include <iostream>
using namespace std;
int findMissingUsingSum(int arr[], int n);
int findMissingUsingXOR(int arr[], int n);

int main(){
    int n = 5;
    int arr[n] = {1, 2, 3, 5};
    // cout << "Missing = " << findMissingUsingSum(arr, n) << endl;
    cout << "Missing = " << findMissingUsingXOR(arr, n) << endl;
    return 0;
}

// missing between 1 to N
/*
1, 2, 4, 5
*/

// optimal
int findMissingUsingSum(int arr[], int n){
    int sumN = n*(n + 1) / 2;
    int arrSum = 0;

    for(int i =  0; i < n; i++){
        arrSum += arr[i];
    }
    return sumN - arrSum;
}

// Using XOR slighlty better

int findMissingUsingXOR(int arr[], int n){
    int xor1 = 0;
    int xor2 = 0;
    /*      1 2 3 4 5
            1 2 4 5*/
    for(int i = 0; i < n-1; i++){    // NOTE:  a^a = 0 && 0^a = a;
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ n;

    return xor1 ^ xor2;
}