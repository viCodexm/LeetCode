class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> positive, negative;
        for (int num : nums) {
            if (num < 0) negative.push(num);
            else positive.push(num);
        }
        bool isPos = true;
        vector<int> ans;
        while (!positive.empty() || !negative.empty()) {
            if (isPos) {
                ans.push_back(positive.front());
                positive.pop();
            } else {
                ans.push_back(negative.front());
                negative.pop();
            }
            isPos = !isPos;
        }
        return ans;
    }
};