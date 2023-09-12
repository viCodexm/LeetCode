class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> dict;
        for (char& c : s)
            dict[c]++;

        int del = 0;
        unordered_set<int> use;
        for (auto& [c, val] : dict) {
            while (val && use.find(val) != use.end()) {
                val--;
                del++;
            }
            use.insert(val);
        }
        return del;
    }
};