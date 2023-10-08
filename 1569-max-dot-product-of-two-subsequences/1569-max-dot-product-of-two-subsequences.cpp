class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size(), m = nums2.size();
        vector<int> cur(m + 1, INT_MIN), prev(m + 1, INT_MIN);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int prod = nums1[i - 1] * nums2[j - 1];
                cur[j] = max({prod, prev[j], cur[j - 1], prod + max(0, prev[j - 1])});
            }
            swap(cur, prev);
        }
        return prev[m];
    }
};