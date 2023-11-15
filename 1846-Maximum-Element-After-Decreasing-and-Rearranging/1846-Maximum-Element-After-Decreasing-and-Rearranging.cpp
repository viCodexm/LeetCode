class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 1;
        const int size = arr.size();
        for (int i = 1; i < size; ++i)
            if (arr[i] >= ans + 1)
                ans++;
        
        return ans;
    }
};
