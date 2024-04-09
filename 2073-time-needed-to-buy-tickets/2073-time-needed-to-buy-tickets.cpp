class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0, cur = tickets[k], unnecessary = 0;
        for (int i = 0; i < tickets.size(); ++i)
            ans += min(cur, tickets[i]);
        for (int i = k + 1; i < tickets.size(); ++i)
            unnecessary += (tickets[i] >= cur);
        return ans - unnecessary;
    }
};