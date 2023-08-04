struct tw {int to, weight;};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dp(n + 1, INT_MAX); dp[k] = 0;
        unordered_map<int, vector<tw>> m;
        // from: [to, weight], [to, weight], [to, weight]...
        for (vector<int> t : times)
            m[t[0]].push_back({ t[1], t[2] });

        queue<int> q; q.push(k);
        int count = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int from = q.front(); q.pop();
                for (tw& next_candidate : m[from]) {
                    if (next_candidate.to == k) continue;
                    int sum = dp[from] + next_candidate.weight;
                    if (sum < dp[next_candidate.to]) {
                        dp[next_candidate.to] = sum;
                        q.push(next_candidate.to);
                    }
                }
            }
        }
        if (find(dp.begin() + 1, dp.end(), INT_MAX) != dp.end())
            return -1;
        return *max_element(dp.begin() + 1, dp.end());
    }
};