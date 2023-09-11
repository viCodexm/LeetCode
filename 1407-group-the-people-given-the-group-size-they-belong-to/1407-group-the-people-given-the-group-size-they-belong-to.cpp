class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> answer;
        unordered_map<int, vector<int>> groups;
        int i = 0;
        for (int& gs : groupSizes) {
            auto& group = groups[gs];
            group.push_back(i);
            if (group.size() == gs) {
                answer.push_back(group);
                group.clear();
            }
            i++;
        }
        return answer;
    }
};