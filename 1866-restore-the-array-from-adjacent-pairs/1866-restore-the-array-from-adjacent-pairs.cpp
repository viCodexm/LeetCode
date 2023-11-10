class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> dict;
        for (vector<int>& p : adjacentPairs) {
            dict[p[0]].push_back(p[1]);
            dict[p[1]].push_back(p[0]);
        }
        int root = 0;
        for (auto& p : dict)
            if (p.second.size() == 1) {
                root = p.first;
                break;
            }

        vector<int> ans;
        dfs(root, INT_MAX, dict, ans);
        return ans;
    }
    void dfs(int node, int prev, unordered_map<int, vector<int>>& graph, vector<int>& ans) {
        ans.push_back(node);
        for (int nei : graph[node])
            if (nei != prev)
                dfs(nei, node, graph, ans);
    }
};