class Solution {
public:
    bool isNoZero(int x) {
        while (x > 0) {
            if (!(x % 10)) {
                return false;
            }
            x /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        const int half = n / 2;
        vector<int> ans(2, -1);
        for (int i = 1; i <= half; ++i) {
            if (isNoZero(i) && isNoZero(n - i)) {
                return {i, n - i};
            }
        }
        return ans;
    }
};