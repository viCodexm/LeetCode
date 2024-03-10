class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1, st2;
        for (int num : nums1)
            st1.insert(num);

        for (int num : nums2)
            if (st1.find(num) != st1.end())
                st2.insert(num);

        return vector<int>(st2.begin(), st2.end());
    }
};