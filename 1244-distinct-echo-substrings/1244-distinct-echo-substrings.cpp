class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int size = text.size();
        set<string> ans;
        for (int start = 0; start < size; ++start) {
            string sub; sub += text[start];
            int max = (size - start) / 2;
            for (int len = 1; len <= max; ++len) {
                if (sub == text.substr(start + sub.size(), sub.size()))
                    ans.insert(sub);
                sub += text[start + len];
            }
        }
        return ans.size();
    }
};