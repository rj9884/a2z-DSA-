#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printMatrix(vector<vector<int>> &matrix);
vector<vector<int>> rotateMatrixByNinty(vector<vector<int>> &matrix);
vector<vector<int>> rotateMatrixByNintyOptimal(vector<vector<int>> &mat);
void swap(int &a, int &b);

int main(){
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    

    cout << "Initial Matrix: " << endl;

    printMatrix(matrix);

    cout << "Resultant Matrix: " << endl;
    // vector<vector<int>>ans = rotateMatrixByNinty(matrix);
    vector<vector<int>>ans = rotateMatrixByNintyOptimal(matrix);
    printMatrix(ans);
    return 0;
}

void printMatrix(vector<vector<int>> &matrix){
    for ( auto row : matrix) {
        for ( auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// brute
vector<vector<int>> rotateMatrixByNinty(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>>ans(m, vector<int>(n));

    for(int i = 0; i < m; i++) {
        for ( int j = 0; j < n; j++) {
            ans[j][n-1-i] = matrix[i][j];
        }
    }

    return ans;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// Optimal
/* transpose  mat + reverse row*/

vector<vector<int>> rotateMatrixByNintyOptimal(vector<vector<int>> &mat) {
    int n = mat.size();

    for(int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    for (int i = 0; i < n; i++){
        reverse(mat[i].begin(), mat[i].end());
    }
    return mat;
}