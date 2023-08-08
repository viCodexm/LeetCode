class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& req) {
        unordered_map<int, vector<int>> dict;
        unordered_map<int, int> achievable;
        for (vector<int>& v : req)
            dict[v[0]].push_back(v[1]);
        
        vector<int> ans;
        for (int i = 0; i < numCourses; ++i)
            if (!dfs(req, dict, achievable, i, ans))
                return {};
        return ans;
    }
    bool dfs(vector<vector<int>>& req, unordered_map<int, vector<int>>& dict, unordered_map<int, int>& achievable, int i, vector<int>& ans) {
        if (achievable[i] == -1)
            return false;
        if (achievable[i])
            return true;
        achievable[i] = -1;
        for (int& v : dict[i])
            if (!dfs(req, dict, achievable, v, ans))
                return false;
        achievable[i] = true;
        ans.push_back(i);
        return true;
    }
};