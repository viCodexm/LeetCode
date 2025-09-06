using ll = long long;

class Solution {
public:
    int binLen(int x) {
        return floor(log2(x)) +1;
    }
    ll minOperations(vector<vector<int>>& queries) {
        ll ans = 0;
        for (const auto& q : queries) {
            const int l = q[0];
            const int r = q[1];

            const int x = (binLen(l) + 1) >> 1;
            const int y = (binLen(r) + 1) >> 1;

            ll sum = 0;
            for (int i = x; i <= y; ++i) {
                const int exp_high = 2 * i;
                const int exp_low = exp_high - 2;
         
                ll low = (1LL << exp_low);
                ll high = (1LL << exp_high) - 1;

                const ll left = max(low, ll(l));
                const ll right = min(high, ll(r));

                sum += (bool(right >= left) * (right - left + 1) * i);
            }
            ans += (sum + 1) >> 1;
        }
        return ans;
    }
};