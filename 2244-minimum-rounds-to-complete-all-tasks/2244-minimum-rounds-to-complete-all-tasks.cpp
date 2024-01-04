class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> dict;
        for (int& num : tasks)
            dict[num]++;
        int ans = 0;
        for (auto& [num, count] : dict) {
            if (count == 1)
                return -1;
            ans += ceil((double)count / 3);
        }
        return ans;
    }
};