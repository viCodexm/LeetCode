class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        partial_sort(begin(happiness), begin(happiness) + k, end(happiness), greater{});
        int count = 0;
        transform(happiness.begin(), happiness.begin() + k, happiness.begin(),
                   [&count](int& elem) { return std::max(0, elem - count++); });
        return accumulate(begin(happiness), begin(happiness) + k, 0ll);
    }
};