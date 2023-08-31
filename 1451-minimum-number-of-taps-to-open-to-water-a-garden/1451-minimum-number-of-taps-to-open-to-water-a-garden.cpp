class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxreach(n + 1);
        for (int i = 0; i < ranges.size(); ++i) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            maxreach[start] = max(maxreach[start], end);
        }
        int count = 0;
        int end = 0, next_max = 0;
        for (int i = 0; i <= n; ++i) {
            if (i > next_max)
                return -1;
            if (i > end) {
                count++;
                end = next_max;
            }
            next_max = max(next_max, maxreach[i]);
        }
        return count;
    }
};