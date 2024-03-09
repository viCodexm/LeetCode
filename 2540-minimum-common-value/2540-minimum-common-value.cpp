class Solution {
public:
    int borderCheck(int a, int b) {
        if (a == INT_MAX)
            return -1;
        return a;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int id1 = 0, id2 = 0;
        nums1.push_back(INT_MAX); nums2.push_back(INT_MAX);
        while (true) {
            while (nums1[id1] < nums2[id2])
                id1++;
            if (nums1[id1] == nums2[id2])
                return borderCheck(nums1[id1], nums2[id2]);
                
            while (nums2[id2] < nums1[id1])
                id2++;
            if (nums1[id1] == nums2[id2])
                return borderCheck(nums1[id1], nums2[id2]);
        }
        return -1;
    }
};