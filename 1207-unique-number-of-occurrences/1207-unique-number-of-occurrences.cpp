class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> dict, check;
        for (int& num : arr)
            dict[num]++;
        for (auto& [num, count] : dict)
            if (++check[count] >= 2)
                return false;
        return true;
    }
};