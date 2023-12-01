class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int word1Ptr = 0, word2Ptr = 0;
        int str1Ptr = 0, str2Ptr = 0;

        const int w1size = word1.size();
        const int w2size = word2.size();
        while (word1Ptr < w1size && word2Ptr < w2size) {
            if (word1[word1Ptr][str1Ptr++] != word2[word2Ptr][str2Ptr++])
                return false;
            if (str1Ptr == word1[word1Ptr].size()) {
                word1Ptr++;
                str1Ptr = 0;
            }
            if (str2Ptr == word2[word2Ptr].size()) {
                word2Ptr++;
                str2Ptr = 0;
            }
        }
        return word1Ptr == w1size && word2Ptr == w2size;
    }
};
