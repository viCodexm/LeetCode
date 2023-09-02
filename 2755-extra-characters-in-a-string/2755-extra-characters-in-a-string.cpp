struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = NULL;
        isEnd = false;
    }
};
struct Trie {
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(string s) {
        TrieNode* tmp = root;
        for (char& c : s) {
            if (!tmp->children[c - 'a'])
                tmp->children[c - 'a'] = new TrieNode();
            tmp = tmp->children[c - 'a'];
        }
        tmp->isEnd = true;
    }
};
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie trie;
        for (string& word : dictionary)
            trie.insert(word);

        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1] + 1;
            TrieNode* node = trie.root;
            for (int j = i; j < n; ++j) {
                if (!node->children[s[j] - 'a'])
                    break;
                node = node->children[s[j] - 'a'];
                if (node->isEnd)
                    dp[i] = min(dp[i], dp[j + 1]);
            }
        }
        return dp[0];
    }
};