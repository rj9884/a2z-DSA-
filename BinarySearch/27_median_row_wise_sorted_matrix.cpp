#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMedianBrute(vector<vector<int>>& matrix);
int countLessEqual(vector<int>& row, int mid);
int findMedian(vector<vector<int>>& matrix);

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    cout << findMedianBrute(matrix) << endl;
    cout << findMedian(matrix) << endl;

    return 0;
}


// Brute
/* Time Complexity: O(M*N*(log(M*N))), Space : O(M*N) */
int findMedianBrute(vector<vector<int>>& matrix) {
        
    vector<int> elements;

    for (auto& row : matrix) {
        for (int val : row) {
            elements.push_back(val);
        }
    }

    sort(elements.begin(), elements.end());

    int n = elements.size();
    return elements[n / 2];
}


// Optimal
/* Time Complexity: O(rows × log(max - min) × log(cols)), Space : O(1)*/

int countLessEqual(vector<int>& row, int mid) {
    return upper_bound(row.begin(), row.end(), mid) - row.begin();
}

int findMedian(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int low = matrix[0][0];

    int high = matrix[0][cols - 1];
    for (int i = 1; i < rows; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][cols - 1]);
    }

    while (low < high) {
        int mid = (low + high) / 2;

        int count = 0;
        for (int i = 0; i < rows; i++) {
            count += countLessEqual(matrix[i], mid);
        }

        if (count < (rows * cols + 1) / 2)
            low = mid + 1;
        else
            high = mid;
    
    }
    return low;
}