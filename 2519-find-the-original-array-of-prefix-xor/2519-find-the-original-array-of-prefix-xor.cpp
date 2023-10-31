class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans = pref;
        int prev = ans[0];
        for (int i = 1; i < ans.size(); ++i) {
            ans[i] = prev ^ pref[i];
            prev ^= ans[i];
        }
        return ans;
    }
};