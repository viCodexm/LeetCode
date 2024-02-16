class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> dict;
        for (int e : arr)
            dict[e]++;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& [key, val] : dict)
            pq.push(val);
        while (k > 0 && !pq.empty()) {
            k -= pq.top();
            if (k >= 0)
                pq.pop();
        }
        return pq.size();
    }
};