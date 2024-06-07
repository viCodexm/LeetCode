class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode() : children(26, nullptr) { isEnd = false; }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (!current->children[c - 'a'])
                current->children[c - 'a'] = new TrieNode();
            current = current->children[c - 'a'];
        }
        current->isEnd = true;
    }

    string shortestRoot(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.length(); ++i) {
            TrieNode* next = current->children[word[i] - 'a'];
            if (!next)
                return word;
            
            current = next;
            if (current->isEnd)
                return word.substr(0, i + 1);
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie dictTrie;
        for (string word : dictionary)
            dictTrie.insert(word);
        
        string word, newSentence;
        istringstream iss(sentence);
        while (iss >> word)
            newSentence += dictTrie.shortestRoot(word) + " ";

        newSentence.pop_back();
        return newSentence;
    }
};