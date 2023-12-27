class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        const int size = colors.size();
        int l = 0, r = 0, time = 0;
        while (l < size) {
            int max = 0, sum = 0;
            while (r < size && colors[l] == colors[r]) {
                if (neededTime[r] > max)
                    max = neededTime[r];
                sum += neededTime[r];
                r++;
            }
            time += sum - max;
            l = r;
        }
        return time;
    }
};