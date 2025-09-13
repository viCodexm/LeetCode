class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int maxFreqSum(string s) {
        int maxVow = 0;
        int maxCon = 0;
        int freq[128];
        memset(freq, 0, sizeof(freq));
        for (const char& c : s) {
            freq[c]++;
            if (isVowel(c)) {
                maxVow = max(maxVow, freq[c]);
            } else {
                maxCon = max(maxCon, freq[c]);
            }
        }
        return maxVow + maxCon;
    }
};