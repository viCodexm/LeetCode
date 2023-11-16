class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        const int n = nums[0].size();
        set<int> st;
        for (string& num : nums)
            st.insert(stoi(num, 0, 2));
        
        for (int num = 0; num <= n; ++num) {
            if (st.find(num) == st.end()) {
                string ans = bitset<16>(num).to_string();
                return ans.substr(16 - n);
            }
        }
        return "";
    }
};
