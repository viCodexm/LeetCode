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
    int ans = INT_MAX;
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie trie;
        for (string& word : dictionary)
            trie.insert(word);
        vector<vector<vector<int>>> dp(s.size(), vector<vector<int>>(s.size(), vector<int>(26, -1)));
        dfs(s, 0, trie.root, trie.root, 0, 0, dp);
        return ans;
    }
    bool dfs(string& s, int idx, TrieNode* root, TrieNode* node, int skipped, int depth, vector<vector<vector<int>>>& dp) {
        if (idx >= s.size()) {
            if (node->isEnd)
                ans = min(ans, skipped);
            else ans = min(ans, skipped + depth);
            return false;
        }
        if (skipped >= ans)
            return false;
        

        char c = s[idx];
        if (dp[idx][skipped][c - 'a'] == 1005)
            return false;
        // has next
        if (node->children[c - 'a'])
            dfs(s, idx + 1, root, node->children[c - 'a'], skipped, depth + 1, dp);
        if (node->isEnd)
            dfs(s, idx, root, root, skipped, 0, dp);
        else dfs(s, idx - depth + 1, root, root, skipped + 1, 0, dp);
        return dp[idx][skipped][c - 'a']++;
    }
};