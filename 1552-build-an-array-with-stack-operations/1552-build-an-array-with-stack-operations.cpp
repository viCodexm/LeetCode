class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int idx = 0;
        for (int& i : target) {
            while (idx < i) {
                ans.push_back("Push");
                idx++;
                if (idx != i)
                    ans.push_back("Pop");
            }
        }
        return ans;
    }
};