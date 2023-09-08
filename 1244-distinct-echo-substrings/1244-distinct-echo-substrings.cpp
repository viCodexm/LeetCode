#define ll long long
class Solution {
public:
    int distinctEchoSubstrings(string s) {
        int size = s.size();
        set<string> ans;
        for (int windowSize = 1; windowSize <= size / 2; ++windowSize) {
            
            for (int l = 0, r = windowSize, count = 0; l < size - windowSize; ++l, ++r) {
                (s[l] == s[r]) ? count++ : count = 0;
                if (count == windowSize) {
                    ans.insert(s.substr(l, r - l));
                    count--;
                }
            }
        }
        return ans.size();
    }
};