class Solution {
public:
    int integerBreak(int n) {
        if (n < 4)
            return n - 1;
        
        switch (n % 3) {
        case 0:
            return pow(3, n / 3);
        case 1:
            return pow(3, n / 3 - 1) * 4;
        }
        return pow(3, n / 3) * 2;
    }
};