typedef long long ll;
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        ll total = 0;

        for (const char& c : s)
            isdigit(c) ? total *= (c - '0') : total++;
        
        for (int i = s.size() - 1; i >= 0; --i) {
            k %= total;

            if (!k && isalpha(s[i]))
                return string(1, s[i]);

            isdigit(s[i]) ? total /= (s[i] - '0') : total--;
        }
        return "";
    }
};