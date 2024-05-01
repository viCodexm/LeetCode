class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pos = word.find_first_of(ch);
        if (pos != string::npos)
            reverse(begin(word), begin(word) + pos + 1);      
        return word;
    }
};