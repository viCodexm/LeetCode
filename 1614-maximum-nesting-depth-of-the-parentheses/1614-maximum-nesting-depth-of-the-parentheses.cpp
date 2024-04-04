class Solution {
public:
    int maxDepth(string s) {
        int open = 0, max = 0;
        for (char c : s) {
            open += (c == '(') - (c == ')');
            max = std::max(max, open);
        }
        return max;
    }
};