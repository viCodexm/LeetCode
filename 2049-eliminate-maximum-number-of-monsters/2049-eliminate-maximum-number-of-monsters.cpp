class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        const int size = dist.size();
        vector<float> time(size, 0);
        for (int i = 0; i < size; ++i)
            time[i] = ((float)dist[i] / speed[i]);
        
        sort(time.begin(), time.end());

        for (int i = 0; i < size; ++i)
            if (i >= time[i])
                return i;
        
        return size;
    }
};