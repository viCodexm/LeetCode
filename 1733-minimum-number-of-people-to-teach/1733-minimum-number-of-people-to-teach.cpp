#define all(v) v.begin(), v.end()
class Solution {
public:
    bool hasCommonLang(vector<int>& langs1, vector<int>& langs2) {
        for (auto& l1 : langs1) {
            for (auto& l2 : langs2) {
                if (l1 == l2) {
                    return true;
                }
            }
        }
        return false;
    }
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<pair<int, int>> fakeFriends;
        for (vector<int>& fr : friendships) {
            int guy1 = fr[0] - 1;
            int guy2 = fr[1] - 1;
            if (!hasCommonLang(languages[guy1], languages[guy2])) {
                fakeFriends.push_back({guy1, guy2});
            }
        }
        
        int min = INT_MAX;
        for (int lang = 1; lang <= n; ++lang) {
            int need = 0;
            unordered_set<int> learned;
            for (const auto& [guy1, guy2] : fakeFriends) {
                if (!learned.contains(guy1)) {
                    need += (find(all(languages[guy1]), lang) == languages[guy1].end());
                    learned.insert(guy1);
                }
                if (!learned.contains(guy2)) {
                    need += (find(all(languages[guy2]), lang) == languages[guy2].end());
                    learned.insert(guy2);
                }
            }
            min = std::min(min, need);
        }
        return min;
    }
};