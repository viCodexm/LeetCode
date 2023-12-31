class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        const int size = s.size();
        unordered_map<char, int> dict;
        int ans = -1;
        for (int i = 0; i < size; ++i) {
            char& c = s[i];
            if (dict.find(c) != dict.end())
                ans = max(ans, i - dict[c] - 1);
            else dict[c] = i;
        }
        return ans;
    }
};