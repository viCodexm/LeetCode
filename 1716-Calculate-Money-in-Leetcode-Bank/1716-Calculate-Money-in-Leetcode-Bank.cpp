class Solution {
public:
    int totalMoney(int n) {
        int totalWeeks = n / 7;
        int remainsDays = n % 7;
        return (28 * totalWeeks) + (7 * (totalWeeks - 1) * totalWeeks / 2) + (totalWeeks * 2 + 1 + remainsDays) * remainsDays / 2;
    }
};
