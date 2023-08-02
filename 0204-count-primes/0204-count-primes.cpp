class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> w(n, true);
        w[0] = w[1] = false;
        int count = 0;
        for (int div = 2; div < n; ++div)
            if (w[div]) {
                count++;
                long long x = (long long)div * div;
                if (x < n)
                    for (int num = x; num < n; num += div)
                        w[num] = false;
            }
                
        return count;
    }
};