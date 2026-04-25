
#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target);

int main() {
    vector<vector<int>>mat = {{2,3,4,6},{7,8,10,12},{14,20,23,26}};
    cout << searchMatrix(mat, 9) << endl;
    return 0;
}


// Optimal
/* time : O(m + n), space : O(1)*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int row = 0;
    int col = m-1;

    while(row < n && col >= 0 ) {
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] < target) row++;
        else col--;
    }
    return false;
}