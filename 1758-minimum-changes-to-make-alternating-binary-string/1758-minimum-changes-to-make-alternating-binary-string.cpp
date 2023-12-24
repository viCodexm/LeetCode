class Solution {
public:
    int minOperations(string s) {
        int s01 = 0;
        const int size = s.size();
        for (int i = 0; i < size; ++i)
            s01 += i & 1 && s[i] == '1';
        return min(size - s01, s01);
    }
};