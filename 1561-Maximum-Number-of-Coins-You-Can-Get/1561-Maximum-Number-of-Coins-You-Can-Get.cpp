class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        const int n = piles.size() / 3;
        int ans = 0, idx = 1;
        for (int i = 0; i < n; ++i) {
            ans += piles[idx];
            idx += 2;
        }
        return ans;
    }
};
