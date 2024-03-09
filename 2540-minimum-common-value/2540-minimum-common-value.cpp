class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size();
        const int m = nums2.size();
        int i = 0, j = 0, diff = 0;
        while (i < n && j < m) {
            diff = nums1[i] - nums2[j];
            if (!diff) return nums1[i];
            (diff < 0) ? ++i : ++j;
        }
        return -1;
    }
};