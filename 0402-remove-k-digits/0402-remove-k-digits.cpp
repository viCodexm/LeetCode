class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for (const char& c : num) {
            while (!ans.empty() && k && ans.back() > c) {
                ans.pop_back(); k--;
            }
            if (!ans.empty() || c != '0')
                ans.push_back(c);
        }
        while (!ans.empty() && k) {
            ans.pop_back(); k--;
        }
        return (ans == "") ? "0" : ans;
    }
};