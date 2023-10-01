class Solution {
public:
    string reverseWords(string s) {
        int n = 0;
        int lastPos = 0;
        auto swapWord = [](string &s, int it1, int it2) {
            while (it1 < it2)
            {
                swap(s[it1], s[it2]);
                it1++;
                it2--;
            }
        };
        bool first = true;
        while (n != -1)
        {
            lastPos = n;
            n = s.find(' ', lastPos + 1);
            if (n == -1)
                continue;
            swapWord(s, lastPos + !first, n - 1);
            first = false;
        }
        swapWord(s, lastPos + 1 - first, s.size() - 1);
        return s;
    }
};