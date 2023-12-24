class Solution {
public:
    int minOperations(string s) {
        int a = 0, b = 0;
        const int size = s.size();
        for (int i = 0; i < size; ++i)
            if (s[i] == '1')
                if (i & 1)
                    a++;
                else b++;
            else if (i & 1)
                    b++;
                else a++;
        return min(a, b);
    }
};