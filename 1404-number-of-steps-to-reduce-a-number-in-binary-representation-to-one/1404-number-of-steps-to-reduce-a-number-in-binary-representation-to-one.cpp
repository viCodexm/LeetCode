class Solution {
public:
    int numSteps(string s) {
        const int n = s.size();
        int operations = 0, carry = 0;
        for (int i = n - 1; i > 0; --i) {
            if (((s[i] - '0') + carry) & 1) {
                operations += 2;
                carry = 1;
            } else operations++;
        }
        return operations + carry;
    }
};