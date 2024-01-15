class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> dict;
        for (vector<int>& match : matches) {
            dict[match[0]];
            dict[match[1]]++;
        }
        vector<int> a, b;
        for (auto& [key, val] : dict) {
            if (!val)
                a.push_back(key);
            else if (val == 1)
                b.push_back(key);
        }
        return {a, b};
    }
};