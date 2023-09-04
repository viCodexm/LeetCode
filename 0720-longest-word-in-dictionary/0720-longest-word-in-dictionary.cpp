struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
};
struct Trie {
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    int insert(string& word) {
        bool ok = true;
        TrieNode* tmp = root;
        for (int i = 0; i < word.size() - 1; ++i) {
            char c = word[i] - 'a';
            if (!tmp->children[c])
                tmp->children[c] = new TrieNode();
            tmp = tmp->children[c];
            
            if (!tmp->isEnd)
                ok = false;
        }
        char c = word[word.size() - 1] - 'a';
        if (!tmp->children[c])
            tmp->children[c] = new TrieNode();
        tmp = tmp->children[c];
        tmp->isEnd = true;
        return ok ? word.size() : 0;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        string ans;
        sort(words.begin(), words.end(), [](const string& left, const string& right) {
            return left.size() < right.size();
        });
        for (string& word : words) {
            int size = trie.insert(word);
            if (size > ans.size())
                ans = word;
            else if (size == ans.size() && ans > word)
                ans = word;
        }
        return ans;
    }
};