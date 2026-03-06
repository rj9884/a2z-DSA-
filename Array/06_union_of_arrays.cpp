#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> unionArr(int arr1[], int arr2[], int n, int m){
    set<int>st;
    for(int i = 0; i < n; i++){
        st.insert(arr1[i]);
    }
    for(int i = 0; i < m; i++){
        st.insert(arr2[i]);
    }
    vector<int>temp;
    for(auto it : st){
        temp.push_back(it);
    }
    return temp;
}

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int arr1[3] = {1, 2, 1};
    int arr2[4] = {4, 1, 3, 2};
    print(arr1, 3);
    print(arr2, 4);

    vector<int> temp = unionArr(arr1, arr2, 3, 4);
    for(int i = 0; i < temp.size(); i++){
        cout << temp[i] << " ";
    }
    return 0;
}