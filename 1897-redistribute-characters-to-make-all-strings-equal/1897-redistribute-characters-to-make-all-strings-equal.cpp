class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> dict;
        const int size = words.size();
        for (string& word : words)
            for (char& c : word)
                dict[c]++;

        for (auto& e : dict)
            if (e.second % size != 0)
                return false;
        return true;
    }
};