#include <iostream>
#include <vector>
using namespace std;


void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int rearrangeElements(int arr[], int n);
void reArrangeElementsBySign(int arr[], int n);
vector<int> alternateNumber(vector<int> arr);

int main(){
    int n = 6;
    int arr[] = {4, -2, -1, 3, 5, -7};
    vector<int>vec = {4, -2, -1, 3, 5, -7, 6};
    print(arr, n);
    // rearrangeElements(arr, n);
    // print(arr, n);
    // reArrangeElementsBySign(arr, n);
    vector<int> ans = alternateNumber(vec);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

// brute force 
int rearrangeElements(int arr[], int n){
    int positiveArr[n/2];
    int negativeArr[n/2];
    int neg = 0;
    int pos = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            negativeArr[neg++] = arr[i];
        }else{
            positiveArr[pos++] = arr[i];
        }
    }
    // print(positiveArr, n/2);
    // print(negativeArr, n/2);
    neg = 0; pos = 0;
    for(int k = 0; k < n / 2; k++){
        arr[2*k] = positiveArr[pos++];
        arr[2*k + 1] = negativeArr[neg++];
    }
    cout << "After Rearrange: " << endl;
    
    print(arr, n);

    return 0;
}

// better
void reArrangeElementsBySign(int arr[], int n){
    int posIdx = 0;
    int negIdx = 1;
    int ans[n];
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            ans[negIdx] = arr[i];
            negIdx += 2;
        }else{
            ans[posIdx] = arr[i];
            posIdx += 2;
        }
    }
    print(ans, n);
}


// second variety : When neg[] != pos[] --> n is odd

vector<int> alternateNumber(vector<int> arr){
    int size = arr.size();
    vector<int> pos, neg;

    for(int i = 0; i < size; i++){
        if(arr[i] < 0){
            neg.push_back(arr[i]);
        }else{
            pos.push_back(arr[i]);
        }
    }

    if(pos.size() > neg.size()){
        for(int i = 0; i < neg.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i + 1] = neg[i];
        }

        int idx = neg.size() * 2;

        for(int i = neg.size(); i < pos.size(); i++){
            arr[idx] = pos[i];
            idx++;
        }
    }else{
        for(int i = 0; i < pos.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i + 1] = neg[i];
        }
        int idx = pos.size() * 2;

        for(int i = pos.size(); i < neg.size(); i++){
            arr[idx] = neg[i];
            idx++;
        }
    }
    return arr;
}