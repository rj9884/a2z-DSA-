#include <iostream>
#include <vector>
using namespace std;

int nCr(int n, int r);
void printNtheRow(int n);
void printPascalTriangle(int n);
vector<int> generateRow(int row);
vector<vector<int>> pascalTriangle(int n);
void printPascal(vector<vector<int>>nums);


int main () {
    // cout << nCr(4,2) << endl;
    // printNtheRow(6);
    // printPascalTriangle(6);
    vector<vector<int>>ans = pascalTriangle(6);
    printPascal(ans);
    return 0;
}


// prob 1: Given R & C find element at that place .e.g : r=5, c=3

// element = r-1Cc-1

int nCr(int n, int r) {
    int res = 1;
    for ( int i = 0; i < r; i++) {
        res *= n-i;
        res /= i+1;
    }
    return res;
}

// prob 2: print any row of pascal triangle
// time : O(n) , space : O(1)

void printNtheRow(int n) {
    int ans = 1;
    cout << ans << " ";
    for (int i = 1; i < n; i++) {
        ans = ans * (n-i);
        ans = ans / i;
        cout << ans << " ";
    }
}










// prob 3: Given row number N, print entire pascal triangle


vector<int> generateRow(int row) {
    vector<int>ansRow;
    long long ans = 1;
    ansRow.push_back(ans);
    for (int col = 1; col < row; col++) {
        ans = ans * (row-col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
void printPascalTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        printNtheRow(i);
        cout << endl;
    } 
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>>ans;
    for (int i = 1; i <= n; i++) {
        ans.push_back(generateRow(i));
    }
    return ans;
}

void printPascal(vector<vector<int>>nums) {
    for (auto row: nums) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}