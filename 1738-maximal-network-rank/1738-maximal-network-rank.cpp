class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> v(n, vector<int>(0,0));
        for (vector<int>& road : roads) {
            v[road[0]].push_back(road[1]);
            v[road[1]].push_back(road[0]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans, calc_rank(i, j, v));
            }
        }
        return ans;
    }

    int calc_rank(int i, int j, vector<vector<int>>& v) {
        bool connected = find(v[i].begin(), v[i].end(), j) != v[i].end();
        
        return v[i].size() + v[j].size() - connected;
    }
};