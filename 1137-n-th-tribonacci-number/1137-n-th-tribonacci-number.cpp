class Solution {
public:
    int tribonacci(int n) {
        if (!n)
            return 0;
        if (n < 3)
            return 1;
        int prev3 = 0, prev2 = 1, prev1 = 1, ans = 0;
        for (int i = 3; i <= n; ++i) {
            ans = prev1 + prev2 + prev3;
            prev3 = prev2; prev2 = prev1; prev1 = ans;
        }
        return ans;
    }
};