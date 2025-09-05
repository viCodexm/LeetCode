class Solution {
public:
    int romanToInt(string_view s) {
        static unordered_map<char, int> dict = {
            {'M', 1000}, {'D', 500}, {'C', 100},
            {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}
        };
        int ans = 0, cur = 0, next = 0;
        const int size = s.size() - 1;
        for (int i = 0; i < size; ++i) {
            cur = dict[s[i]];
            next = dict[s[i + 1]];
            ans += (cur < next) ? -cur : cur;
        }
        ans += dict[s.back()];
        return ans;
    }
};