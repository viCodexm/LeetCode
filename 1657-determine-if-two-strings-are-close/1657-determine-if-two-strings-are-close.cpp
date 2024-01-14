class Solution {
public:
    bool sameLetters(string& word1, string& word2) {
        unordered_set<char> st;
        for (char& c : word1)
            st.insert(c);

        for (char& c : word2)
            if (st.find(c) == st.end())
                return false;
        return true;
    }
    string getHash(string& word) {
        unordered_map<char, int> dict;
        for (char& c : word)
            dict[c]++;
        priority_queue<int> pq;
        for (auto& [_, val] : dict)
            pq.push(val);
        
        string ans;
        while (!pq.empty()) {
            ans += pq.top(); pq.pop();
        }
        return ans;
    }
    bool closeStrings(string word1, string word2) {
        return sameLetters(word1, word2) && getHash(word1) == getHash(word2);
    }
};