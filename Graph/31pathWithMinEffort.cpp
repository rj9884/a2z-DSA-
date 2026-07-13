#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == n - 1 && col == m - 1)
                return effort;

            for (int i = 0; i < 4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < m) {

                    int newEffort = max(
                        effort,
                        abs(heights[newRow][newCol] - heights[row][col])
                    );

                    if (newEffort < dist[newRow][newCol]) {
                        dist[newRow][newCol] = newEffort;
                        pq.push({newEffort, {newRow, newCol}});
                    }
                }
            }
        }

        return 0;
    }
};

/* Time : O(n * m * 4 * log(n * m)) or O(E log(V)), Space : O(n * m) */

int main() {
    Solution obj;

    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    cout << obj.minimumEffortPath(heights) << endl;

    return 0;
}