class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        const int size = s.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i; j < size; ++j) {
                const int num = stoi(s.substr(i, j - i + 1));
                if (low <= num && num <= high)
                    ans.push_back(num);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};