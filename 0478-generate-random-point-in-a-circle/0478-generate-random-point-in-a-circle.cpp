class Solution {
    double radius;
    double x;
    double y;
public:
    Solution(double radius, double x_center, double y_center) : radius(radius), x(x_center), y(y_center) {}
    
    vector<double> randPoint() {
        static random_device rd;
        static mt19937 gen(rd());
        uniform_real_distribution<double> rad(0, radius * radius);
        static uniform_real_distribution<double> pi(0, 2 * acos(-1.0));

        double r = sqrt(rad(gen));
        double o = pi(gen);

        return { x + r * cos(o), y + r * sin(o) };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */