class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int steps = 1; steps <= 60; ++steps) {
            num1 -= num2;
            if (num1 < steps) {
                break;
            }
            if (__builtin_popcount(num1) <= steps) {
                return steps;
            }
        }
        return -1;
    }
};