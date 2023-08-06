class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int8_t mask = 0;
        for (vector<int>& triple : triplets) {
            if (triple[0] > target[0] || triple[1] > target[1] || triple[2] > target[2])
                continue;

            if (triple[0] == target[0])
                mask |= (1 << 0);

            if (triple[1] == target[1])
                mask |= (1 << 1);

            if (triple[2] == target[2])
                mask |= (1 << 2);

            if (mask == 0b111)
                return true;
        }

        return false;
    }
};