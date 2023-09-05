class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](const string& left, const string& right) {
            if (left.size() == right.size())
                return left < right;
            return left.size() > right.size();
        });
        for (string& word : dictionary) {
            int idx = 0;
            int size = word.size();
            for (char& c : s) {
                if (idx >= word.size())
                    return word;
                char need = word[idx];
                if (c == need)
                    idx++;
            }
            if (idx >= word.size())
                return word;
        }
        
        return "";
    }
};