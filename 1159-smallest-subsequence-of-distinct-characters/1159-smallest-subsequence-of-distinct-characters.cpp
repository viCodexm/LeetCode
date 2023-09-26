class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> count;
        for (const char& c : s)
            count[c]++;

        string str;
        set<int> seen;

        for (const char& c : s) {
            count[c]--;

            if (seen.contains(c))
                continue;
            
            while (!str.empty() && c < str.back() && count[str.back()] > 0) {
                seen.erase(str.back());
                str.pop_back();
            }

            str.push_back(c);
            seen.insert(c);
        }
        return str;
    }
};