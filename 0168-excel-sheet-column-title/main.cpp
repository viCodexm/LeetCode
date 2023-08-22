class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber--) {
            ans += 'A' + columnNumber % 26;
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
