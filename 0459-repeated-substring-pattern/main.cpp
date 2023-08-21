class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i < s.size(); ++i) {
            if (s == s.substr(i, s.size() - 1) + s.substr(0, i))
                return true;
        }
        return false;
    }
};
