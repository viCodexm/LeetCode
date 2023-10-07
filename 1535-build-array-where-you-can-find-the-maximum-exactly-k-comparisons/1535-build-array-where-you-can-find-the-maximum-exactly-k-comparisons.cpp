typedef long long ll;
const int modulo = 1e9 + 7;
class Solution {
public:
    ll dp[51][102][51];
    ll solve(int cur, int curmax, int cur_k, int n, int m, int k) {
        if (cur == n)
            return cur_k == k;
        
        if (dp[cur][curmax + 1][cur_k] != -1)
            return dp[cur][curmax + 1][cur_k];

        ll ans = 0;
        for (int i = 1; i <= m; ++i) {
            int c1 = curmax;
            int c2 = cur_k;
            if (curmax < i) {
                c1 = i;
                c2++;
            }
            ans += solve(cur + 1, c1, c2, n, m, k) % modulo;
        }
        return dp[cur][curmax + 1][cur_k] = ans % modulo;
    }

    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, n, m, k);
    }
};