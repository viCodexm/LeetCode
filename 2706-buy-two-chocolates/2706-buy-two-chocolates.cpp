class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        partial_sort(prices.begin(), prices.begin() + 2, prices.end());
        const int sum = money - prices[0] - prices[1];
        return sum >= 0 ? sum : money;
    }
};