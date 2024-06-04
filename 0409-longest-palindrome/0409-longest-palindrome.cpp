class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> dict;
        for (char c : s)
            dict[c]++;

        int odd = 0;
        for (auto e : dict)
            odd += e.second & 1;

        return s.size() - odd + (odd > 0);
    }
};