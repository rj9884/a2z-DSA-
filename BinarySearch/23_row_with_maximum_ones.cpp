#include <iostream>
#include <vector>

using namespace std;

int lowerbound(vector<int> &nums, int x);
int rowWithMax1s(vector<vector<int>>&mat);
int rowWithMax1sBrute(vector<vector<int>> &mat);

int main() {
    vector<vector<int>>mat = {{0,0,0,1,1,1},{0,0,1,1,1,1},{0,0,0,0,1,1},{0,0,1,1,1,1}};
    cout << rowWithMax1s(mat) << endl;
    cout << rowWithMax1sBrute(mat) << endl;
    return 0;
}



// Brute

int rowWithMax1sBrute(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    int cnt_max = 0;
    int idx = -1;

    for(int i = 0; i < n; i++) {
        int cnt_ones = 0;
        for(int j = 0; j < m; j++) {
            cnt_ones += mat[i][j];
        }
        if(cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            idx = i;
        }
    }
    return idx;
}

// Optimal
int lowerbound(vector<int> &nums, int x) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = n;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(nums[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>>&mat) {
    int max_cnt = 0;
    int idx = -1;
    int n = mat.size();
    int m = mat[0].size();

    for(int i = 0; i < n; i++) {
        int cnt_ones = m - (lowerbound(mat[i], 1));
        if(cnt_ones > max_cnt) {
            max_cnt = cnt_ones;
            idx = i;
        }
    }
    return idx;
}