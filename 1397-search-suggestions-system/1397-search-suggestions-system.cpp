class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> answer;
        int start = 0, size = products.size();
        string prefix;
        for (char& c : searchWord) {
            prefix += c;
            int new_start = lower_bound(products.begin() + start, products.end(), prefix) - products.begin();
            answer.push_back({});
            for (int i = new_start; i < min(new_start + 3, size) && !products[i].compare(0, prefix.size(), prefix); ++i)
                answer.back().push_back(products[i]);

            start = new_start;
        }
        return answer;
    }
};