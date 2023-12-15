class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> dict;
        for (vector<string>& vec : paths) {
            dict[vec[0]]++;
            dict[vec[1]];
        }
        for (auto& [key, val] : dict)
            if (!val)
                return key;
        return "";
    }
};