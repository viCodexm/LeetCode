class Solution {
public:
    int maxScore(string s) {
        const int size = s.size();
        int right = count(s.begin() + 1, s.end(), '1');
        int left = s[0] == '0';
        int ans = left + right;
        for (int i = 1; i < size - 1; ++i) {
            left += s[i] == '0';
            right -= s[i] == '1';
            ans = max(ans, left + right);
        }
        return ans;
    }
};