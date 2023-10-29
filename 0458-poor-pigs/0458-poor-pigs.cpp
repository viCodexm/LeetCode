class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int b = minutesToTest / minutesToDie + 1, x = 0;
        for (int p = 1; p < buckets; ++x) p *= b;
        return x;
    }
};