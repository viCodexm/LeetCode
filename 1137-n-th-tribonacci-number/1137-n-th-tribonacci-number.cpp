class Solution {
public:
    int tribonacci(int n) {
        if (!n)
            return 0;
        if (n < 3)
            return 1;
        int prev[4];
        prev[0] = 0; prev[1] = prev[2] = 1;
        for (int i = 3; i <= n; ++i) {
            prev[3] = prev[2] + prev[1] + prev[0];
            prev[0] = prev[1]; prev[1] = prev[2]; prev[2] = prev[3];
        }
        return prev[3];
    }
};