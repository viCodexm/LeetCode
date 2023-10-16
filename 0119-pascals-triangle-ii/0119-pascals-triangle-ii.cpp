class Solution {
public:
    vector<int> getRow(int rowIndex) {
        map<pair<int, int>, int> dp;
        dp[{0, 0}] = 1;
        dp[{1, 0}] = dp[{1, 1}] = 1;
        int len = 3;
        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = 0; j < len; ++j)
                dp[{i, j}] = dp[{i - 1, j}] + dp[{i - 1, j - 1}];
            
            len++;
        }
        vector<int> ans;
        for (int j = 0; j < rowIndex + 1; ++j)
            ans.push_back(dp[{rowIndex, j}]);
        return ans;
    }
};