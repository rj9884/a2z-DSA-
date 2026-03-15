/*
** Superior element n: <onleft :smaller than n>n <on right : greater than n>
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> superiorElementBrute(vector<int> arr);
vector<int> superiorElements(vector<int>&a);
void display(vector<int>nums);

int main(){
    vector<int>arr = {1,2,2,1};
    cout << "Given array: ";
    display(arr);
    cout << "Using Brute: " << endl;
    cout << "Superior Elements: ";
    vector<int>ans = superiorElementBrute(arr);
    display(ans);
    cout << "Optimal: " << endl;;
    vector<int> ans1 = superiorElements(arr);
    cout << "Superior Elements: ";
    display(ans1);
    return 0;
}


void display(vector<int>nums){
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

vector<int> superiorElementBrute(vector<int> arr){
    int n = arr.size();
    vector<int>ans;

    for (int i = 0; i < n; i++){
        int leader = true;

        for(int j = i+1; j < n; j++){
            if(arr[j] >= arr[i]){
                leader = false;
                break;
            }
        }
        if(leader == true){
            ans.push_back(arr[i]);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// optimal sol

vector<int> superiorElements(vector<int>&a) {
    
    int n = a.size();
    int max = INT_MIN;
    vector<int>ans;

    for(int i = n-1; i >= 0; i--){
        if(a[i] > max){
            max = a[i];
            ans.push_back(a[i]);
        }
    }
    return ans;
}