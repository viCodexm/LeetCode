class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dist1 = abs(x - z);
        int dist2 = abs(y - z);
        return (dist1 == dist2) ? 0 : dist1 < dist2 ? 1 : 2;
    }
};