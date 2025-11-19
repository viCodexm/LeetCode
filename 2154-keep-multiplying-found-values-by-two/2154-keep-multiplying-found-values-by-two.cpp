class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int w[1001]{0};
        for (int& x : nums) {
            w[x] = true;
        }
        int i = original;
        while (i < 1001) {
            if (!w[i]) {
                return i;
            }
            i *= 2;
        }
        return i;
    }
};