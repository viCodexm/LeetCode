class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        vector<string> v(numRows);
        int idx = 0; bool descent = 0;
        for (char& c : s) {
            if (idx < 0) {
                descent = false;
                idx = 1;
            }
            if (idx > numRows - 2) {
                descent = true;
            }
            v[idx] += c;
            if (descent)
                idx--;
            else idx++;
        }
        string ans;
        for (string& s : v)
            ans += s;

        return ans;
    }
};