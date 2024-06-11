class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted = heights;
        sort(sorted.begin(), sorted.end());
        int count = 0;
        for (int i = 0; i < sorted.size(); ++i)
            count += (sorted[i] != heights[i]);
        return count;
    }
};