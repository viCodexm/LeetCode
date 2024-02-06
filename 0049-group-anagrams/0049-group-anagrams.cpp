class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<int, int>, int> dict;
        // sum, length      group num
        vector<vector<string>> groups;
        for (string& str : strs) {
            map<int, int> w;
            for (char c : str)
                w[c]++;
            auto it = dict.find(w);
            if (it != dict.end())
                groups[it->second].push_back(str);
            else {
                groups.push_back({str});
                dict[w] = groups.size() - 1;
            }
        }
        return groups;
    }
};