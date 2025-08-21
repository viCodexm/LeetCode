class Solution {
public:
    int scanLeft(vector<vector<int>>& mat, int i) {
        int result = 0;
        const int m = mat[0].size();
        for (int j = 0; j < m; ++j) {
            int minHeight = mat[i][j];
            for (int l = j; l >= 0 && minHeight > 0; --l) {
                minHeight = min(minHeight, mat[i][l]);
                result += minHeight;
            }   
        }
        return result;
    } 
    int numSubmat(vector<vector<int>>& mat) {
        const int n = mat.size();
		const int m = mat[0].size();
        int result = scanLeft(mat, 0);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mat[i][j] *= (1 + mat[i - 1][j]);
            }
            result += scanLeft(mat, i);
        }
        return result;
    }
};