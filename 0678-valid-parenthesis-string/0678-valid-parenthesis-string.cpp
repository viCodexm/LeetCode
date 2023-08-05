class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftBrackets, stars;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
            case '(':
                leftBrackets.push(i);
                break;
            case ')':
                if (!leftBrackets.empty())
                    leftBrackets.pop();
                else if (!stars.empty())
                    stars.pop();
                else return false;
                break;
            case '*':
                stars.push(i);
                break;
            }
        }
        while (!leftBrackets.empty() && !stars.empty()) {
            if (leftBrackets.top() > stars.top())
                return false;
            leftBrackets.pop();
            stars.pop();
        }
        return leftBrackets.empty();
    }
};