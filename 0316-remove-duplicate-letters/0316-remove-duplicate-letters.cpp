class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> count;
        for (const char& c : s)
            count[c]++;

        deque<char> dq;
        set<int> seen;

        for (const char& c : s) {
            count[c]--;

            if (seen.contains(c))
                continue;
            
            while (!dq.empty() && c < dq.back() && count[dq.back()] > 0) {
                seen.erase(dq.back());
                dq.pop_back();
            }

            dq.push_back(c);
            seen.insert(c);
        }
        return string(dq.begin(), dq.end());
    }
};