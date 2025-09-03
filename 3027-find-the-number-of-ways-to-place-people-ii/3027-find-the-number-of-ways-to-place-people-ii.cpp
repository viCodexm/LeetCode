class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        auto compare = [](const vector<int>& left, const vector<int>& right) {
            return (left[0] == right[0]) ? left[1] < right[1] : left[0] > right[0];
        };
        sort(begin(points), end(points), compare);
        const int n = points.size();
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            int y = INT_MAX;
            const int yi = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                const int yj = points[j][1];
                if (yj >= yi && y > yj) {
                    answer++;
                    y = yj;
                }
            }
        }
        return answer;
    }
};