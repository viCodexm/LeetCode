class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> dp = {0};
        int res = 0;
        for (const string& s : arr) {
            int a = 0, duplicate = 0;
            for (char c : s) {
                const int bit = (1 << (c - 'a'));
                duplicate |= a & bit;
                a |= bit;
            }
            if (duplicate > 0)
                continue;
            
            for (int i = dp.size() - 1; i >= 0; --i) {
                if ((dp[i] & a) > 0)
                    continue;
                dp.push_back(dp[i] | a);
                res = max(res, __builtin_popcount(dp[i] | a));
            }
        }
        return res;
    }
};