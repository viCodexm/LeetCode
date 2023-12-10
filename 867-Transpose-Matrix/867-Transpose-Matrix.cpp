class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        vector<vector<int>> mat(cols, vector<int>(rows));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                mat[j][i] = matrix[i][j];
        return mat;
    }
};
