class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int need = nums.size() / 3;
        unordered_map<int, int> dict;
        for (int& e : nums)
            dict[e]++;

        vector<int> ans;
        for (auto& e : dict)
            if (e.second > need)
                ans.push_back(e.first);
        return ans;
    }
};