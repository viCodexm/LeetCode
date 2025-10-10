class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        const int n = energy.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n - k; ++i) {
            dp[i] += energy[i];
            dp[i + k] += dp[i];
        }
        for (int i = n - k; i < n; ++i) {
            dp[i] += energy[i];
        }
        return max(
            *max_element(end(dp) - k, end(dp)),
            *max_element(end(energy) - k, end(energy))
        );
    }
};