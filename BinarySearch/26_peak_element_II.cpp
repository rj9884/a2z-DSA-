#include <iostream>
#include <vector>

using namespace std;
int findMaxIndex(vector<vector<int>>&mat , int col);
vector<int> peakGrid(vector<vector<int>>&mat);

int main() {
    vector<vector<int>>mat = {{10, 20, 15}, {21, 30, 14}, {7, 16, 32}};
    vector<int>ans = peakGrid(mat);
    for(auto val : ans) {
        cout << val << endl;
    }
    return 0;
}


/* time ; O(log(m) * n) , space: O(1)*/

int findMaxIndex(vector<vector<int>>&mat , int col) {
    int n = mat.size();
    int m = mat[0].size();
    int maxVal = -1;
    int idx = -1;

    for(int i = 0; i < n; i++) {
        if(mat[i][col] > maxVal) {
            maxVal = mat[i][col];
            idx = i;
        }
    }
    return idx;
}

vector<int> peakGrid(vector<vector<int>>&mat) {
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = m-1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        int maxRowIdx = findMaxIndex(mat, mid);
        int left = mid - 1 >= 0 ? mat[maxRowIdx][mid - 1] : -1;
        int right = mid + 1 < m ? mat[maxRowIdx][mid + 1] : -1;

        if(mat[maxRowIdx][mid] > left && mat[maxRowIdx][mid] > right) return {maxRowIdx, mid};
        else if(mat[maxRowIdx][mid] < left) high = mid - 1;
        else low = mid + 1;
    }
    return {-1, -1};
}