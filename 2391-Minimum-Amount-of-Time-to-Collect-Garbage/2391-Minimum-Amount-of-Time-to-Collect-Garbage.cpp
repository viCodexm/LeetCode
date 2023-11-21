class Solution {
public:
    int _travel(char type, vector<string>& g, vector<int>& travel) {
        int ans = 0;
        const int size = g.size();
        ans += count(g[0].begin(), g[0].end(), type);
        
        int buffer = 0;
        for (int i = 1; i < size; ++i) {
            buffer += travel[i - 1];
            int _count = count(g[i].begin(), g[i].end(), type);
            if (_count > 0) {
                ans += buffer + _count;
                buffer = 0;
            }
        }
        return ans;
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        return _travel('M', garbage, travel) + _travel('P', garbage, travel) + _travel('G', garbage, travel);
    }
};
