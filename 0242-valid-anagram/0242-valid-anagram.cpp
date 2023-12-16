class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> note;
		for (auto& e : s) {
			note[e]++;
		}
		for (auto& e : t) {
			note[e]--;
		}
		for (auto& a : note) {
			if (a.second != 0) return false;
		}
		return true;
    }
};