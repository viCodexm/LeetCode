class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int& num : nums)
            pq.push(num * num);
        const int size = pq.size();
        vector<int> res(size);
        for (int i = 0; i < size; ++i) {
            res[i] = pq.top(); pq.pop();
        }
        return res;
    }
};