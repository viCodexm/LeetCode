class Solution {
public:
    bool canPlace(vector<vector<char>>& board, int x, int y, char num) {
        const int n = board.size();
        const int box_x = (x / 3) * 3;
        const int box_y = (y / 3) * 3;
        for (int i = 0; i < n; ++i) {
            if (board[x][i] == num || board[i][y] == num || board[box_x + i / 3][box_y + i % 3] == num) {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, vector<pair<int, int>>& emptyCells, int start) {
        const int n = board.size();
        const int m = emptyCells.size();
        for (int i = start; i < m; ++i) {
            const auto& [x, y] = emptyCells[i];
            for (char num = '1'; num <= '9'; ++num) {
                if (!canPlace(board, x, y, num)) {
                    continue;
                }
                board[x][y] = num;
                if (solve(board, emptyCells, start + 1)) {
                    return true;
                }
                board[x][y] = '.';
            }
            return false;
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        const int n = board.size();
        vector<pair<int, int>> emptyCells;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') {
                    emptyCells.push_back({i, j});
                }
            }
        }
        solve(board, emptyCells, 0);
    }
};