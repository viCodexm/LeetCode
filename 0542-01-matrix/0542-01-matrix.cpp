class Solution {
public:
    vector<int> dirs = {1, 0, -1, 0, 1};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dis(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (mat[i][j] == 0)
                {
                    dis[i][j] = 0;
                    q.push({i, j});
                }
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for (int k = 0; k < 4; ++k)
            {
                int ii = i + dirs[k];
                int jj = j + dirs[k + 1];
                if (0 <= ii && ii < n && 0 <= jj && jj < m && dis[ii][jj] == -1)
                {
                    dis[ii][jj] = dis[i][j] + 1;
                    q.push({ii, jj});
                }
            }
        }
        return dis;
    }
};