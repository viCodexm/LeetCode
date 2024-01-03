class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = 0;
        for (string& col : bank) {
            int cur = count(col.begin(), col.end(),'1');
            ans += prev * cur;
            if (cur)
                prev = cur;
        }
        return ans;
    }
};