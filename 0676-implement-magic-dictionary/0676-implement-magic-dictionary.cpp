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

    void insert(string& word) {
        TrieNode* tmp = root;
        for (char& c : word) {
            if (!tmp->children[c - 'a'])
                tmp->children[c - 'a'] = new TrieNode();
            tmp = tmp->children[c - 'a'];
        }
        tmp->isEnd = true;
    }
    bool search_with_one_mistake(string& word) {
        TrieNode* tmp = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i] - 'a';

            for (char j = 0; j < 26; ++j) {
                if (c == j)
                    continue;
                if (search(i + 1, word, tmp->children[j]))
                    return true;
            }
            if (tmp->children[c])
                tmp = tmp->children[c];
            else return false;
        }
        return false;
    }
    bool search(int idx, string& word, TrieNode* tmp) {
        if (!tmp)
            return false;
        for (int i = idx; i < word.size(); ++i) {
            if (tmp->children[word[i] - 'a'])
                tmp = tmp->children[word[i] - 'a'];
            else return false;
        }
        return tmp->isEnd;
    }
};
class MagicDictionary {
    Trie trie;
public:
    MagicDictionary() {}
    
    void buildDict(vector<string> dictionary) {
        for (string& word : dictionary)
            trie.insert(word);
    }
    
    bool search(string searchWord) {
        return trie.search_with_one_mistake(searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */