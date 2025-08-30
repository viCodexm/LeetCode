class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }
        
        vector<pair<string, int>> candidates(freq.begin(), freq.end());
        partial_sort(candidates.begin(), candidates.begin() + k, candidates.end(),
                    [](const auto& a, const auto& b) {
                        return a.second > b.second || 
                            (a.second == b.second && a.first < b.first);
                    });
                    
        vector<string> answer(k);
        for (int i = 0; i < k; ++i) {
            answer[i] = candidates[i].first;
        }
        return answer;
    }
};