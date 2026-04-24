#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>&nums, int target);
int matrixSearchBrute(vector<vector<int>>&mat, int target);
int matrixSearchBetter(vector<vector<int>>&mat, int target);
int matrixSearch(vector<vector<int>>&mat, int target);

int main() {
    vector<vector<int>>mat = {{2,3,4,6},{7,8,10,12},{14,20,23,26}};
    cout << matrixSearchBrute(mat, 10) << endl;
    cout << matrixSearchBetter(mat, 10) << endl;
    cout << matrixSearch(mat, 9) << endl;
    return 0;
}

int binarySearch(vector<int>&nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
} 

// Brute Approach
/* time: O(n * m) , space : O(1)*/

int matrixSearchBrute(vector<vector<int>>&mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == target) return 1;
        }
    }
    return 0;
}

// Better
/* time : O(n) * log(n)*/
int matrixSearchBetter(vector<vector<int>>&mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    for(int i = 0; i < n; i++) {
        if(mat[i][0] < target && target < mat[i][m-1]) {
            if(binarySearch(mat[i], target)) return 1;
            return 0;
        }
    }
    return -1;
}

// optimized
/* time : log(nm) , space : O(1) */
int matrixSearch(vector<vector<int>>&mat, int target) {
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = n * m - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        int row = mid / m;
        int col = mid % m;
        if(mat[row][col] == target) return 1;
        else if(mat[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return 0;
}