class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circle = 0, square = 0;
        for (int student : students) {
            circle += !(student);
            square += student;
        }
        for (int sandwich : sandwiches) {
            if (!sandwich && !circle)
                return square;
            if (sandwich && !square)
                return circle;
            
            circle -= !(sandwich);
            square -= sandwich;
        }
        return 0;
    }
};