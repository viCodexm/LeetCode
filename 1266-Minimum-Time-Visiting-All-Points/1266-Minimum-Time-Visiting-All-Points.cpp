class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            const int currX = points[i][0];
            const int currY = points[i][1];
            const int targetX = points[i + 1][0];
            const int targetY = points[i + 1][1];
            ans += max(abs(targetX - currX), abs(targetY - currY));
        }
        return ans;
    }
};
