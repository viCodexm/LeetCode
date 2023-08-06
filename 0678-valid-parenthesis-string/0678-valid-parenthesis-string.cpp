class Solution {
public:
    bool checkValidString(string s) {
        int balanced = 0;
        for (char& c : s) {
            balanced += (c == '(' || c == '*') - (c == ')');
            if (balanced < 0)
                return false;
        }
        if (balanced == 0)
            return true;
        balanced = 0;
        reverse(s.begin(), s.end());
        for (char& c : s) {
            balanced += (c == ')' || c == '*') - (c == '(');
            if (balanced < 0)
                return false;
        }
        return true;
    }
};