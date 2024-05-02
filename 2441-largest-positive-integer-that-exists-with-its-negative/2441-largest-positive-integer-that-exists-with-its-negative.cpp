class Solution {
public:
    int findMaxK(vector<int>& nums) {
        priority_queue<int, vector<int>, less<int>> pq;

        unordered_set<int> st;
        for (int num : nums) {
            pq.push(num);
            if (num < 0)
                st.insert(-num);
        }
        
        while (!pq.empty()) {
            int ans = pq.top(); pq.pop();
            if (st.contains(ans))
                return ans;
        }
        return -1;
    }
};