class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        vector<bool> w(n, true);
        w[0] = w[1] = false;
        for (long long div = 2; div < n; ++div)
            if (w[div])
                for (long long num = div * div; num < n; num += div)
                    w[num] = false;
                
        return accumulate(w.begin(), w.end(), 0);
    }
};