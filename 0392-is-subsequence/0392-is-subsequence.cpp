class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int sz = s.size(), tz = t.size();
        for (int i = 0, r = 0; i < sz; ++i) {
            char& c = s[i];
            while (c != t[r] && r < tz) { r++; }
            if (r >= tz)
                return false;
            r++;
        }
        return true;
    }
};