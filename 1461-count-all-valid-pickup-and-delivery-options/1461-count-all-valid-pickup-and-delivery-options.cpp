const int modulo = 1e9 + 7;
class Solution {
public:
    int countOrders(int n) {
        long long ans = 1;
        for (int mn = 2; mn <= n; ++mn)
            ans = (ans * mn * (2 * mn - 1)) % modulo;
        return (int) ans;
    }
};