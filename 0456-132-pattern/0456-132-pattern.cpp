class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int size = nums.size();
        if (size < 3)
            return false;
        stack<int> st;
        vector<int> mins(size);
        mins[0] = nums[0];
        for (int i = 1; i < size; ++i)
            mins[i] = min(mins[i - 1], nums[i]);
        
        for (int i = size - 1; i > 0; --i) {
            if (nums[i] <= mins[i])
                continue;

            while (!st.empty() && st.top() <= mins[i])
                st.pop();

            if (!st.empty() && st.top() < nums[i])
                return true;
            st.push(nums[i]);
        }

        return false;
    }
};