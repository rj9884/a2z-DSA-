#include <iostream>
#include <vector>
using namespace std;

vector <int> spiralMatrixTraversal( vector<vector<int>>&mat);
void printMatrix(vector<vector<int>>&mat);
void printList(vector<int>&arr);

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    cout << "Matrix: " << endl;
    printMatrix(matrix);
    cout << "Spiral Matrix: " << endl;
    vector<int>ans = spiralMatrixTraversal(matrix);
    printList(ans);
    return 0;
}


void printMatrix(vector<vector<int>>&mat){
    for (auto row : mat) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void printList(vector<int>&arr) {
    for (auto val : arr) {
        cout << val << " ";
    }
    cout << endl;
}
vector <int> spiralMatrixTraversal( vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<int> ans;

    int left = 0;
    int right = m-1;
    int top = 0;
    int bottom = n-1;

    while (left <= right && top <= bottom){
        for (int i = left; i <= right; i++){
        ans.push_back(mat[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++){
            ans.push_back(mat[i][right]);
        }
        right--;
        if(top <= bottom){
            for (int i = right; i >= left; i--){
            ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        if(left <= right){
            for (int i = bottom; i >= top; i--){
            ans.push_back(mat[i][left]);
            }
            left++;
        }
        
    }
    return ans;
}