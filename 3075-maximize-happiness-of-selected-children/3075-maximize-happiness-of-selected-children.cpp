class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        partial_sort(begin(happiness), begin(happiness) + k, end(happiness), greater{});
        for (int i = 1; i < k; ++i)
            happiness[i] = max(0, happiness[i] - i);
        return accumulate(begin(happiness), begin(happiness) + k, 0ll);
    }
};