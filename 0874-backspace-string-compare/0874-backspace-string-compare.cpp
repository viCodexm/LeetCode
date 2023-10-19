class Solution {
public:
    bool backspaceCompare(string _a, string _b) {
        string a;
        for (char& c : _a)
            if (c == '#') {
                if (!a.empty())
                    a.pop_back();
            }
            else a += c;

        string b;
        for (char& c : _b)
            if (c == '#') {
                if (!b.empty())
                    b.pop_back();
            }
            else b += c;

        return a == b;
    }
};