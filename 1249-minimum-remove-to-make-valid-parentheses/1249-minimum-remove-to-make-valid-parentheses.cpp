class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string str;
        int cur = 0;
        for (char c : s) {
            cur += (c == '(') - (c == ')');
            if (cur >= 0) str.push_back(c); else cur = 0;
        }
        cur = 0;
        s = "";
        for (int i = str.size() - 1; i >= 0; --i) {
            cur += (str[i] == '(') - (str[i] == ')');
            if (cur <= 0) s.push_back(str[i]); else cur = 0;
        }
        return string(s.rbegin(), s.rend());
    }
};