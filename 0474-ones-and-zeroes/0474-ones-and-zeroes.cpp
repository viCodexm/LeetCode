#define all(v) begin(v), end(v)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        map<pair<int, int>, int> dp;
        dp[{0, 0}] = 0;

        for (const auto &s : strs) {
            int zeros = 0, ones = 0;
            for (char c : s) {
                zeros += c == '0';
                ones += c == '1';
            }

            map<pair<int, int>, int> newdp;

            for (const auto &[state, val] : dp) {
                int used0 = state.first + zeros;
                int used1 = state.second + ones;

                if (used0 > m || used1 > n) {
                    continue;
                }

                if (!dp.count({used0, used1}) || dp[{used0, used1}] < val + 1) {
                    newdp[{used0, used1}] = val + 1;
                }
            }

            for (const auto &[state, val] : newdp) {
                dp[state] = max(dp[state], val);
            }
        }

        int ans = 0;
        for (const auto &[_, val] : dp) {
            ans = max(ans, val);
        }
        return ans;
    }
};