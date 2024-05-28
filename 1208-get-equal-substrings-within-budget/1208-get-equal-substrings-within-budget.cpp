class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0, cost = 0, start = 0;
        const int n = s.size();
        for (int i = 0; i < n; ++i) {
            cost += abs(s[i] - t[i]);
            while (cost > maxCost) {
                cost -= abs(s[start] - t[start]);
                start++;
            }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};