class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> dict;
        for (char c : s)
            dict[c]++;
        priority_queue<pair<int, char>> pq;
        for (auto& [c, cnt] : dict)
            pq.push({cnt, c});
        string ans;
        while (!pq.empty()) {
            ans += string(pq.top().first, pq.top().second); pq.pop();
        }
        return ans;
    }
};