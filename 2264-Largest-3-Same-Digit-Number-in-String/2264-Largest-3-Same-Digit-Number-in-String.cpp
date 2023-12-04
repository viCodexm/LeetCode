class Solution {
public:
    bool check(char c, string& num) {
        const int size = num.size() - 2;
        for (int i = 0; i < size; ++i)
            if (num[i] == c && num[i + 1] == c && num[i + 2] == c)
                return true;
        return false;
    }
    string largestGoodInteger(string num) {
        for (int i = '9'; i >= '0'; --i)
            if (check(i, num))
                return string(3, i);
        return "";
    }
};
