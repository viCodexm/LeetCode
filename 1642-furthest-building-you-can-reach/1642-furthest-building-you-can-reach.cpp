class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> built;
        const int size = heights.size();
        for (int i = 1; i < size; ++i) {
            int diff = heights[i] - heights[i - 1];
            if (diff <= 0)
                continue;

            bricks -= diff;
            built.push(diff);

            if (bricks < 0) {
                bricks += built.top(); built.pop();
                ladders--;
            }
            if (ladders < 0)
                return i - 1;
        }
        return size - 1;
    }
};