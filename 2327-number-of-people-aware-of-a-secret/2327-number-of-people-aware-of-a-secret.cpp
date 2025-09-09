using ll = long long;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        deque<ll> deq(forget, 0);
        deq.back() = 1;
        long long cur = (delay == 1);
        const int mod = 1e9+7;
        
        for (int i = 1; i < n; ++i) {
            deq.pop_front();
            deq.push_back(cur);
            cur -= deq.front();
            cur += deq[forget - delay];
            cur = (cur % mod + mod) % mod;
        }
        
        long long result = 0;
        for (auto num : deq) {
            result = (result + num) % mod;
        }
        return result;
    }
};