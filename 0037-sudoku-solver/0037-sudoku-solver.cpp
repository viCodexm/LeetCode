class Solution {
public:

	bool isSafe(vector<vector<char>>& board, int& row, int& col, char& num) {
		int n = board.size();
		for (int i = 0; i < n; ++i) {
			if (board[row][i] == num)
				return false;
			if (board[i][col] == num)
				return false;

			int sr = row / 3;
			int sc = col / 3;
			if (board[3 * sr + (i / 3)][3 * sc + (i % 3)] == num)
				return false;
		}
		return true;
	}

	bool solve(vector<vector<char>>& board, vector<pair<int, int>>& emptyCells, int& startptr) {
		int n = board.size();
		pair<int, int> x;
		for (int i = startptr; startptr < emptyCells.size(); ++i) {
			x = emptyCells[i];
			for (char num = '1'; num <= '9'; ++num)
				if (isSafe(board, x.first, x.second, num)) {
					board[x.first][x.second] = num;
					startptr++;
					bool isNextGood = solve(board, emptyCells, startptr);
					if (isNextGood)
						return true;
					else {
						board[x.first][x.second] = '.';
						startptr--;
					}
				}
			// if we did not filled with any digit
			return false;
		}
		// sudoku completed
		return true;
	}

	void solveSudoku(vector<vector<char>>& board) {
		int startptr = 0;
		vector<pair<int, int>> emptyCells;
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				if (board[i][j] == '.')
					emptyCells.push_back({ i, j });
		solve(board, emptyCells, startptr);
	}

};