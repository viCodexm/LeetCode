class Solution {
public:
    bool is_square(int n) {
        double root = sqrt(n);
        return root == int(root);
    }
    int numSquares(int n) {
        while (n % 4 == 0)
            n /= 4;
        if (n % 8 == 7)
            return 4;
        if (is_square(n))
            return 1;
        const double root = sqrt(n);
        for (int i = 1; i <= root; ++i) {
            if (is_square(n - i * i))
                return 2;
        }
        return 3;
    }
};