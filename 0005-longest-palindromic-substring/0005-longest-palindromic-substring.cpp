class Solution {
public:
    void findPalindrome(int l, int r, string& s, pair<int, int>& res) {
        int n = s.size();
        while (l >= 0 && r < n && s[l] == s[r]) {
            int length = r - l + 1;
            if (length > res.second) {
                res = { l, length };
            }
            l--;
            r++;
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();
        pair<int, int> res = {0, 0}; int l, r;
        for (int centre = 0; centre < n; ++centre) {
            l = r = centre;
            findPalindrome(l, r, s, res);
            l = centre; r = centre + 1;
            findPalindrome(l, r, s, res);
        }
        return s.substr(res.first, res.second);
    }
};