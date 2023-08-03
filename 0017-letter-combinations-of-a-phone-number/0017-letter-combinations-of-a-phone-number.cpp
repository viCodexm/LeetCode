class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        if (digits.empty())
            return answer;
        string cur;
        map<char, string> dict;
        dict['2'] = "abc"; dict['3'] = "def";
        dict['4'] = "ghi"; dict['5'] = "jkl"; dict['6'] = "mno";
        dict['7'] = "pqrs"; dict['8'] = "tuv"; dict['9'] = "wxyz";

        dfs(dict, digits, 0, cur, answer);
        return answer;
    }
    void dfs(map<char, string>& dict, string& digits, int idx, string cur, vector<string>& ans) {
        if (cur.size() == digits.size()) {
            ans.push_back(cur);
            return;
        }
        
        for (char& letter : dict[digits[idx]])
            dfs(dict, digits, idx + 1, cur + letter, ans);
    }
};