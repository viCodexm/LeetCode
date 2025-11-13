class Solution {
public:
    int maxOperations(string s) {
        int ones = s[0] == '1', ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            ones += s[i] == '1';
            if (s[i] == '0' && s[i - 1] == '1') {
                ans += ones;
            }
        }
        return ans;
    }
};