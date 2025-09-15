class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int broken[128];
        memset(broken, 0, sizeof(broken));
        for (const char& c : brokenLetters) {
            broken[c] = true;
        }
        int ans = 0;
        bool bad = false;
        for (const char& c : text) {
            bad |= broken[c];
            if (c == ' ') {
                ans += !bad;
                bad = false;
            }
        }
        ans += !bad;
        return ans;
    }
};