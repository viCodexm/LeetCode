class Solution {
public:
    vector<string> ans;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> dict;
        for (vector<string>& ticket : tickets)
            dict[ticket[0]].push_back(ticket[1]);
        
        for (auto& [_, destinations] : dict)
            sort(destinations.begin(), destinations.end(), std::greater());

        dfs("JFK", dict);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    void dfs(string cur, unordered_map<string, vector<string>>& dict) {
        while (!dict[cur].empty()) {
            string next = dict[cur].back();
            dict[cur].pop_back();
            dfs(next, dict);
        }
        ans.push_back(cur);
    }
};