class Solution {
public:
    const int modulo = 1e9+7;
    int countHomogenous(string s) {
        int ans = 1;
        int streak = 1;
        const int size = s.size();
        for (int i = 1; i < size; ++i) {
            (s[i] == s[i - 1]) ? streak++ : streak = 1;
            ans = (ans + streak) % modulo;
        }

        return ans;
    }
};