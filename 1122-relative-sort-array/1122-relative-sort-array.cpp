class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> dict;
        for (int num : arr1)
            dict[num]++;

        vector<int> ans;
        for (int num : arr2)
            for (; dict[num] > 0; --dict[num])
                ans.push_back(num);
        
        for (auto e : dict) {
            int num = e.first;
            if (e.second > 0)
                for (; dict[num] > 0; --dict[num])
                    ans.push_back(num);
        }
        return ans;
    }
};