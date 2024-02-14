class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> positive, negative;
        for (int num : nums) {
            if (num < 0) negative.push(num);
            else positive.push(num);
        }
        bool isPos = true;
        const int size = nums.size();
        vector<int> ans(size);
        for (int i = 0; i < size; ++i) {
            if (i & 1) {
                ans[i] = negative.front();
                negative.pop();
            } else {
                ans[i] = positive.front();
                positive.pop();
            }
        }
        return ans;
    }
};