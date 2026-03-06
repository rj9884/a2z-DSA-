#include <iostream>
#include <unordered_map>

using namespace std;


/*
better sol --> using Hashing
*/

int majorityElement(int arr[], int n){
    unordered_map<int, int>mpp;

    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }
    for(auto it: mpp){
        if(it.second > n / 2) return it.first;
    }
    return -1;
}

/*optimal --> moore's voting algorithm
*/

int majorityElementMoore(int arr[], int n){
    int cnt = 0;
    int el;
    for(int i = 0; i < n; i++){
        if(cnt == 0){
            cnt = 1;
            el = arr[i];
        }else if(arr[i] == el){
            cnt++;
        }else{
            cnt--;
        }
    }

    int cnt1 = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == el) cnt1++;
    }
    if(cnt1 > n / 2) return el;

    return -1;

}
int main(){
    int n = 10;
    int arr[n] = {1, 2, 1, 2, 2, 3, 4, 2, 2, 2};
    // cout << majorityElement(arr, n) << endl;
    cout << majorityElementMoore(arr, n) << endl;
    return 0;
}