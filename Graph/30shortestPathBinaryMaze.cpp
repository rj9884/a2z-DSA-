#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int, int>> q;

        dist[0][0] = 1;
        q.push({0, 0});

        int delRow[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int delCol[] = {1, 1, 0, -1, -1, -1, 0, 1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int row = it.first;
            int col = it.second;

            if (row == n - 1 && col == n - 1)
                return dist[row][col];

            for (int i = 0; i < 8; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 &&
                    dist[row][col] + 1 < dist[nrow][ncol]) {

                    dist[nrow][ncol] = dist[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 0, 0}
    };

    cout << "Shortest Path Length = "
         << obj.shortestPathBinaryMatrix(grid) << endl;

    return 0;
}