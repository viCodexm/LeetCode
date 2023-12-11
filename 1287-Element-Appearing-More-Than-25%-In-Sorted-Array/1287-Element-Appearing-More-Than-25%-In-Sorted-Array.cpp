class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {    
        const int size = arr.size();
        int needCount = size / 4 + 1;
        int prev = arr[0], count = 1;
        for (int i = 1; i < size; ++i) {
            if (prev == arr[i]) {
                count++;
                if (count >= needCount)
                    return arr[i];
            }
            else count = 1;
            prev = arr[i];
        }
        return arr[0];
    }
};
