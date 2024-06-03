class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        for (; i < s.size() && j < t.size(); ++i)
            j += (s[i] == t[j]);
        
        return t.size() - j;
    }
};