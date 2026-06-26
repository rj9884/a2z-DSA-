#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& ans, int sr, int sc, int color, int iniColor, int delRow[], int delCol[]) {
        ans[sr][sc] = color;
        int n = ans.size();
        int m = ans[0].size();

        for(int i = 0; i < 4; i++) {
            int nrow = sr + delRow[i];
            int ncol = sc + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] == iniColor && ans[nrow][ncol] != color) {
                dfs(ans, nrow, ncol, color, iniColor, delRow, delCol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;
        int iniColor = image[sr][sc];
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        dfs(ans, sr, sc, color, iniColor, delRow, delCol);

        return ans;
    }
};

int main() {
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sr = 1;
    int sc = 1;
    int color = 2;

    Solution sol;
    vector<vector<int>>res = sol.floodFill(image, sr, sc, color);
    cout << "Result:" << endl;

    for(const auto &row: res ) {
        for(const auto & val: row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}