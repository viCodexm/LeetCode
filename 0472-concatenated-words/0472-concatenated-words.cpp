class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> ans;
        for (string& word : words) {
            int size = word.size();
            vector<bool> dp(size + 1);
            dp[0] = true;
            for (int i = 1; i <= size; ++i)
                for (int j = (i == size); !dp[i] && j < i; ++j)
                    dp[i] = dp[j] && dict.count(word.substr(j, i - j));
            
            if (dp[size])
                ans.push_back(word);
        }
        return ans;
    }
};