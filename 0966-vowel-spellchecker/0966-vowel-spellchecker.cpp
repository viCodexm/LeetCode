#define all(v) begin(v), end(v)
#define umap unordered_map
#define uset unordered_set
#define pb push_back

class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
                || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    string to_lower(string str) {
        transform(all(str), begin(str), [](unsigned char c) {
            return tolower(c);
        });
        return str;
    }
    string joker(string str) {
        transform(all(str), begin(str), [this](unsigned char c) {
            return isVowel(c) ? '*' : c;
        });
        return str;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        uset<string> same(all(wordlist));
        umap<string, string> lower;
        umap<string, string> vowel;
        for (const string& s : wordlist) {
            string low = to_lower(s);
            string reg = joker(low);
            if (!lower.count(low)) {
                lower[low] = s;
            }
            if (!vowel.count(reg)) {
                vowel[reg] = s;
            }
        }

        vector<string> answer;
        for (const string& q : queries) {
            if (same.count(q)) {
                answer.pb(q);
                continue;
            }

            string low = to_lower(q);
            if (auto it = lower.find(low); it != lower.end()) {
                answer.pb(it->second);
                continue;
            }

            string reg = joker(low);
            if (auto it = vowel.find(reg); it != vowel.end()) {
                answer.pb(it->second);
                continue;
            }

            answer.pb("");
        }
        return answer;
    }
};