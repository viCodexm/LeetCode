class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> dict;
        for (char c : s)
            dict[c]++;

        int sum = 0, max = 0, addOne = 0;
        for (auto e : dict) {
            sum += e.second - (e.second & 1);
            addOne |= (e.second & 1);
        }

        return sum + max + addOne;
    }
};