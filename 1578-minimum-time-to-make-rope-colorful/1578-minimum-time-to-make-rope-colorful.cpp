class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        const int size = neededTime.size();
        colors += '\0';
        char prevColor = colors[0];
        int time = 0, max = 0;
        for (int i = 0; i < size; ++i) {
            if (prevColor == colors[i]) {
                const int timeRight = neededTime[i];
                max = std::max(max, timeRight);
                time += timeRight;
            }
            else {
                time -= max;
                max = 0;
            }
        }
        return time - max;
    }
};