class Solution {
public:
    struct elem {
        int val, start_pos;
    };
    vector<string> findRelativeRanks(vector<int>& score) {
        auto compare = [](elem a, elem b) { return a.val < b.val; };
        priority_queue<elem, vector<elem>, decltype(compare)> elems;
        
        const int n = score.size();
        for (int i = 0; i < n; ++i)
            elems.push({score[i], i});
        
        vector<string> res(n);
        vector<string> places = {"", "Gold Medal", "Silver Medal", "Bronze Medal"};
        
        for (int count = 1; !elems.empty(); ++count) {
            elem tmp = elems.top(); elems.pop();
            res[tmp.start_pos] = (count < 4) ? places[count] : to_string(count);
        }
        return res;
    }
};