class Solution {
public:
    bool isPowerOfFour(long long n) {
        return ((n & n - 1) == 0) && ((n - 1) % 3 == 0);
    }
};