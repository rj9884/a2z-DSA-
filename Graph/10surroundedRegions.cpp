#include <iostream>
#include <vector>

using namespace std;

class Solution {
    private:
        void dfs(vector<vector<char>>& board, int row, int col, vector<vector<int>>& vis) {
            int n = board.size();
            int m = board[0].size();

            vis[row][col] = 1;

            int dRow[] = {-1, 0, 1, 0};
            int dCol[] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++) {
                int nrow = row + dRow[i];
                int ncol = col + dCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                    dfs(board, nrow, ncol, vis);
                }
            }
        }

    public:
        void solve(vector<vector<char>>& board) {
            int n = board.size();
            int m = board[0].size();

            vector<vector<int>>vis(n, vector<int>(m, 0));

            for(int j = 0; j < m; j++) {
                if(!vis[0][j] && board[0][j] == 'O') dfs(board, 0, j, vis); 

                if(!vis[n-1][j] && board[n-1][j] == 'O') dfs(board, n-1, j, vis);
            }
            for(int i = 0; i < n; i++) {
                if(!vis[i][0] && board[i][0] == 'O') dfs(board, i, 0, vis);

                if(!vis[i][m-1] && board[i][m-1] == 'O') dfs(board, i, m-1, vis);
            }

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(!vis[i][j] && board[i][j] == 'O') {
                        board[i][j] = 'X';
                    }
                }
            }

        }
};


int main() {
    vector<vector<char>>board = {
        {'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}
    };

    Solution sol;
    sol.solve(board);
    cout << "Modified board is: " << endl;
    for(const auto row : board) {
        for(const char ch: row) {
            cout << ch << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}