struct Pair {
    int index;
    int value;
};
bool PairComparator(const Pair & a, const Pair & b) {
    return a.value > b.value;
}
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> counts(n);
        vector<vector<int>> adj(n, vector<int>(n, 0));
        for (vector<int>& road : roads) {
            if (road.empty())
                continue;
            int a = road[0]; int b = road[1];
            counts[a]++;
            counts[b]++;
            adj[a][b] = adj[b][a] = true;
        }
        vector<Pair> maxes = findThreeMaxElements(counts);
        int ans = 0;
        int m = maxes.size();
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                bool connected = adj[maxes[i].index][maxes[j].index];
                ans = max(ans, maxes[i].value + maxes[j].value - connected);
            }
        }
        return ans;
    }
    vector<Pair> findThreeMaxElements(vector<int>& nums) {
        vector<Pair> pairs;
        for (int i = 0; i < nums.size(); i++)
            pairs.push_back({ i, nums[i] });

        int maxsize = min(6, (int)nums.size());
        partial_sort(pairs.begin(), pairs.begin() + maxsize, pairs.end(), PairComparator);
        return vector<Pair>(pairs.begin(), pairs.begin() + maxsize);
    }
};