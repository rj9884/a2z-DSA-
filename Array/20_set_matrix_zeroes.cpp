#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> setMatrixZeroesBrute(vector<vector<int>> &matrix);
vector<vector<int>> setMatrixZeroesBetter(vector<vector<int>>&matrix);
vector<vector<int>> setMatrixZeroesOptimal(vector<vector<int>>&matrix);
void printMatrix(vector<vector<int>> &matrix);

int main(){
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    

    cout << "Initial Matrix: " << endl;

    printMatrix(matrix);

    cout << "Resultant Matrix: " << endl;
    // vector<vector<int>>res = setMatrixZeroesBrute(matrix);
    // vector<vector<int>>res = setMatrixZeroesBetter(matrix);
    vector<vector<int>>res = setMatrixZeroesOptimal(matrix);
    printMatrix(res);
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

// Brute Force Approach (time : about O(n^3))
vector<vector<int>> setMatrixZeroesBrute(vector<vector<int>> &matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 0){
                for(int row = 0; row < m; row++){
                    if(matrix[row][j] != 0){
                        matrix[row][j] = -1;
                    }
                    
                }
                for(int col = 0; col < n; col++){
                    if(matrix[i][col] != 0){
                        matrix[i][col] = -1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

// Better Sol time : O(n^2) , space : O(m) + O(n)

vector<vector<int>> setMatrixZeroesBetter(vector<vector<int>>&matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    vector <int> row(m, 0);
    vector <int> col(n, 0);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            
            if (row[i] || col[j]){
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}


// Optimal Sol time : O(n^2) , space : O(1)
vector<vector<int>> setMatrixZeroesOptimal(vector<vector<int>>&matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    // vector <int> row(m, 0); --> matrix[0][...]
    // vector <int> col(n, 0); --> matrix[...][0]

    int col0 = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0){
                // mark the i-th row
                matrix[i][0] = 0;
                // mark the j-th col
                if(j != 0){
                    matrix[0][j] = 0;
                }else{
                    col0 = 0;
                }
            }
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            
            if (matrix[i][j] != 0) {
                // check for col & row
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    if(matrix[0][0] == 0) {
        for (int j = 0; j < n; j++) matrix[0][j] = 0;
    }
    if(col0 == 0){
        for(int i = 0; i < m; i++ ) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}
