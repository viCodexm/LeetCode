#define lVal height[l]
#define rVal height[r]
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int canTrap[20001]{INT_MAX};
        int maxH = 0;
        for (int i = 0; i < n; ++i) {
            maxH = max(maxH, height[i]);
            canTrap[i] = maxH - height[i];
        }
        maxH = 0;
        long long ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            maxH = max(maxH, height[i]);
            ans += min(canTrap[i], maxH - height[i]);
        }
        return ans;
    }
};