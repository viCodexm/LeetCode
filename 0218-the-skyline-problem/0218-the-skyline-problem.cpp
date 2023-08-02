class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        multiset<int> pq{0};
        vector<pair<int, int>> walls;
        for (vector<int>& b : buildings) {
            walls.push_back({b[0], -b[2]});
            walls.push_back({b[1], b[2]});
        }
        sort(walls.begin(), walls.end());

        int currentHeight = 0;
        for (auto& [x, h] : walls) {
            if (h < 0)
                pq.insert(-h);
            else pq.erase(pq.find(h));
            
            int top = *pq.rbegin();
            if (currentHeight != top) {
                currentHeight = top;
                ans.push_back({x, currentHeight});
            }
        }
        return ans;
    }
};