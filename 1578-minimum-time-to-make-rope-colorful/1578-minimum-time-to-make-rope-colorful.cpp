class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        const int size = neededTime.size();
        colors += '\0';
        int l = 0, r = 0, time = 0;
        while (l < size) {
            int max = 0, sum = 0;
            const char colorLeft = colors[l];
            while (colorLeft == colors[r]) {
                const int timeRight = neededTime[r];
                max = std::max(max, timeRight);
                sum += timeRight;
                r++;
            }
            time += sum - max;
            l = r;
        }
        return time;
    }
};