class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        for (int i = 0; i < board.size() && !ans; ++i)
            for (int j = 0; j < board[0].size() && !ans; ++j)
                dfs(board, word, i, j, 0, ans);
        return ans;
    }
    void dfs(vector<vector<char>>& board, string& word, int i, int j, int idx, bool& ans) {
        if (ans || i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || idx >= word.size())
            return;
        if (board[i][j] != word[idx])
            return;
        char tmp = board[i][j];
        board[i][j] = 0;
        dfs(board, word, i + 1, j, idx + 1, ans);
        dfs(board, word, i - 1, j, idx + 1, ans);
        dfs(board, word, i, j + 1, idx + 1, ans);
        dfs(board, word, i, j - 1, idx + 1, ans);
        board[i][j] = tmp;
        ans = ans || idx == word.size() - 1;
    }
};