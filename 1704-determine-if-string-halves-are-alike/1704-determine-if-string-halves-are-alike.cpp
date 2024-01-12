class Solution {
public:
    bool halvesAreAlike(string s) {
        int count1 = 0, count2 = 0;
        int r = s.size() / 2, l = r - 1;
        set<char> need = {'a', 'e', 'i', 'o', 'u',
                        'A', 'E', 'I', 'O', 'U'};
        for (; l >= 0; --l, ++r) {
            count1 += (need.find(s[l]) != need.end());
            count2 += (need.find(s[r]) != need.end());
        }
        return count1 == count2;
    }
};