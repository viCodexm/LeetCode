class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> sIdx(200, 0), tIdx(200, 0);
        const int size = s.size();
        if (size != t.size())
            return false;
        
        for (int i = 0; i < size; ++i) {
            if (sIdx[s[i]] != tIdx[t[i]])
                return false;
            sIdx[s[i]] = i + 1;
            tIdx[t[i]] = i + 1;
        }
        return true;
    }
};