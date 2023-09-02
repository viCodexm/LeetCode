class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = left & right;
        long long dist = (long long)right - left + 1;
        for (int i = 0; i < 32; ++i)
            if ((ans >> i) & 1 && dist > (1 << i))
                ans &= ~(1 << i);
        
        return ans;
    }
};