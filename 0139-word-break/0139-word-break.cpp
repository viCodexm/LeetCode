class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        int maxlen = 0;
        for (string& word : wordDict) {
            maxlen = max(maxlen, static_cast<int>(word.size()));
            words.insert(word);
        }
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i)
            for (int j = max(0, i - maxlen); j < i; ++j)
                if (dp[j]) {
                    string word = s.substr(j, i - j);
                    if (words.find(word) != words.end()) {
                        dp[i] = true;
                        break;
                    }
                }
        return dp[n];
    }
};