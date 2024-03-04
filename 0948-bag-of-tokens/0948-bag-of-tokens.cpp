class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int l = 0, r = tokens.size() - 1, count = 0, max = 0;
        while (l <= r) {
            if (tokens[l] <= power) {
                power -= tokens[l++];
                max = std::max(max, ++count);
            }
            else if (count > 0) {
                power += tokens[r--];
                count--;
            }
            else break;
        }
        return max;
    }
};