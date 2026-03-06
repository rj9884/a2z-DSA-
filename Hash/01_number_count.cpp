#include <iostream>

using namespace std;

int main(){

    int n = 8;
    int arr[] = {2, 3,1, 2, 3, 5, 4, 6};

    int hash[13] = {0};

    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }
    cout << "2 = " << hash[2] << endl;
    cout << "3 = " << hash[3] << endl;
    cout << "5 = " << hash[5] << endl;
    cout << "1 = " << hash[1] << endl;
    return 0;
}