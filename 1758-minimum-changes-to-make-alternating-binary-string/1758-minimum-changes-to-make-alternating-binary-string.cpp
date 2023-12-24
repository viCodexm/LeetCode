class Solution {
public:
    int minOperations(string s) {
        int s10 = 0;
        const int size = s.size();
        for (int i = 0; i < size; ++i)
            s10 += s[i] - '0' == !(i & 1);
        return min(size - s10, s10);
    }
};