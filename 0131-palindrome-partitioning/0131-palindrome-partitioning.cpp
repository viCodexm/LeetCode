class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        vector<string> cur;
        dfs(s, 0, cur, answer);
        return answer;        
    }
    void dfs(string& s, int start, vector<string>& cur, vector<vector<string>>& answer) {
        if (start == s.size()) {
            answer.push_back(cur);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                cur.push_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, cur, answer);
                cur.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
};