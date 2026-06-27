#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>>q;

        vector<vector<int>>vis(n, vector<int>(m, 0));
        int freshCnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                if(grid[i][j] == 1) freshCnt++;
            }
        }

        int maxTm = 0;
        int cnt = 0;
        
        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};

        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int tm = q.front().second;
            maxTm = max(maxTm, tm);
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                    q.push({{nrow, ncol}, tm + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        return (cnt == freshCnt) ? maxTm : -1;
    }
};


/* Time : O( M * N) , Space : O(M * N) */

int main() {
    vector<vector<int>>grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    Solution sol;
    int res = sol.orangesRotting(grid);

    res != -1 ? cout << "Minimum Time Required is: " << res : cout << "Not Possible" ;
    
    cout << endl;
}