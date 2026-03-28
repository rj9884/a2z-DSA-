#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> mergeOverlappingInterval(vector<vector<int>> &arr);
vector<vector<int>> mergeOverlappingIntervalBetter(vector<vector<int>> &arr);

int main() {
    vector<vector<int>>nums = {{1,3},{2,4},{3,5},{6,7}};
    // vector<vector<int>>ans = mergeOverlappingInterval(nums);
    vector<vector<int>>ans = mergeOverlappingIntervalBetter(nums);

    for(auto row: ans) {
        for(auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}


// Brute
/* time : NlogN + O(2N)
   space : O(N)*/
vector<vector<int>> mergeOverlappingInterval(vector<vector<int>> &arr) {
    vector<vector<int>>ans;
    sort(arr.begin(), arr.end());
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        int start = arr[i][0];
        int end = arr[i][1];

        if(!ans.empty() && end <= ans.back()[1]) {
            continue;
        }
        for(int j = i+1; j < n; j++) {
            if(arr[j][0] <= end) {
                end = max(end, arr[j][1]);
            }else{
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

// 

vector<vector<int>> mergeOverlappingIntervalBetter(vector<vector<int>> &arr) {
    vector<vector<int>>ans;
    sort(arr.begin(), arr.end());
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        if(ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}