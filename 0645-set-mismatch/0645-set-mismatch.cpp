class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> dict;
        for (int& num : nums)
            dict[num]++;

        const int n = nums.size();
        int first = 0, second = 0;
        for (int i = 1; i <= n; ++i) {
            switch (dict[i]) {
            case 0:
                second = i;
                break;
            case 2:
                first = i;
            }
        }
        return {first, second};
    }
};