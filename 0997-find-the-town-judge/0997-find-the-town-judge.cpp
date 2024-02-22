class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        set<int> voters;
        vector<int> chosen(n);
        for (auto gay : trust)
        {
            voters.insert(gay[0]);
            chosen[gay[1] - 1]++;
        }
        if (voters.size() >= n)
            return -1;
        for (int i = 0; i < n; ++i)
            if (chosen[i] == n - 1)
                return i + 1;
        return -1;
    }
};