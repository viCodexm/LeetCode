class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> pq;
        const int m = mat[0].size();
        int idx = 0;
        for (vector<int>& row : mat) {
            int soldiers = 0;
            for (int i = 0; i < m && row[i]; ++i)
                soldiers++;

            if (pq.size() < k)
                pq.push({soldiers, idx});
            else if (pq.size() == k && pq.top().first > soldiers) {
                pq.pop(); pq.push({soldiers, idx});
            }
            idx++;
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second); pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};