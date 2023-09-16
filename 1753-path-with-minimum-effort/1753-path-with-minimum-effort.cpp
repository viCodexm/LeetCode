class Solution {
public:
    bool inside(int i, int j, int n, int m) {
        return 0 <= i && i < n && 0 <= j && j < m;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0);
        dist[0][0] = 0;

        vector<int> dirs = {1, 0, -1, 0, 1};

        while (!pq.empty()) {
            auto [effort, x, y] = pq.top(); pq.pop();

            if (effort > dist[x][y])
                continue;
            
            if (x == n - 1 && y == m - 1)
                return effort;

            for (int i = 0; i < 4; ++i) {
                int dx = x + dirs[i], dy = y + dirs[i + 1];
                if (inside(dx, dy, n, m)) {
                    int new_effort = max(effort, abs(heights[x][y] - heights[dx][dy]));
                    if (new_effort < dist[dx][dy]) {
                        dist[dx][dy] = new_effort;
                        pq.emplace(new_effort, dx, dy);
                    }
                }
            }
        }
        return -1;
    }
};