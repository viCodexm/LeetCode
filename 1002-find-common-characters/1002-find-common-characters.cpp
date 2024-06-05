class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> dict;
        for (string& str : words)
            for (char c : str)
                dict[c]++;

        const int max = words.size();
        vector<string> ans;
        for (auto& [letter, total] : dict)
            if (total >= max)
                for (int count = total / max; count > 0; --count)
                    ans.push_back(string{letter});
        return ans;
    }
};