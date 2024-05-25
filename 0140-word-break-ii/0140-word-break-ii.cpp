struct Node {
    int end = 0;
    unordered_map<int, Node*> dict;
};
struct PrefixTree {
    Node root;
    void insert(const string& word) {
        Node* cur = &root;
        for (char c : word) {
            if (!cur->dict[c])
                cur->dict[c] = new Node();
            cur = cur->dict[c];
        }
        cur->end = true;
    }
};

class Solution {
public:
    vector<string> ans;
    PrefixTree pt;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (const string& word : wordDict)
            pt.insert(word);
        dfs(s, 0, &pt.root, "");
        return ans;
    }

    void dfs(string& s, int pos, Node* cur, string made) {
        if (pos >= s.size()) {
            if (cur->end)
                ans.push_back(made);
            return;
        }
        if (!cur)
            return;
        
        char next_char = s[pos++];
        Node* next_in_pt = cur->dict[next_char];
        if (next_in_pt)
            dfs(s, pos, next_in_pt, made + next_char);
        
        Node* next_from_root = pt.root.dict[next_char];
        if (cur->end && next_from_root)
            dfs(s, pos, next_from_root, made + ' ' + next_char);
    }
};