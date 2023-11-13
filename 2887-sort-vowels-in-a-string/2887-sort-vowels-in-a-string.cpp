class Solution {
public:
    bool isVowel(char ch) {
        switch (ch) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'u':
            case 'U':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
                return true;
            default:
                return false;
        }
    }
    string sortVowels(string s) {
        priority_queue<char, vector<char>, greater<char>> pq;
        string t = s;
        int size = s.size();
        for (int i = 0; i < size; ++i)
            if (isVowel(t[i])) {
                pq.push(t[i]);
                t[i] = '*';
            }
        for (int i = 0; i < size; ++i)
            if (t[i] == '*') {
                t[i] = pq.top(); pq.pop();
            }
        return t;
    }
};