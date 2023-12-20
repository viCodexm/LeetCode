class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        const int size = prices.size();
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int i = 0; i < size; ++i) {
            if (prices[i] <= min1) {
                min2 = min1;
                min1 = prices[i];
            } else if (prices[i] < min2)
                min2 = prices[i];
        }
        const int sum = min1 + min2;
        return sum <= money ? money - sum : money;
    }
};