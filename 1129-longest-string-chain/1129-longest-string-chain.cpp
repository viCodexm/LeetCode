class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& left, const string& right) {
            return left.size() < right.size();
        });
        unordered_map<string, int> dict;
        int ans = 0;
        for (string& word : words) {
            int len = 0, wz = word.size();
            for (int i = 0; i < wz; ++i) {
                string copy = word;
                copy.erase(i, 1);
                len = max(len, dict[copy] + 1);
            }
            dict[word] = len;
            ans = max(ans, len);
        }
        return ans;
    }
};