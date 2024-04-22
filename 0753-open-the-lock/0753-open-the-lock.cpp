class Solution {
public:
    int openLock(vector<string>& deadends, const string& target) {
        bitset<10000> seen = 0;
        for (string& s : deadends)
            seen[stoi(s)] = 1;

        if (seen[0])
            return -1;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        seen[0] = 1;
        int targ = stoi(target);
        int dec[4] = {1, 10, 100, 1000};
        while (!q.empty()) {
            auto [turn, s] = q.front(); q.pop();
            if (s == targ)
                return turn;
            int digit, t = s;
            for (int d = 0; d < 4; ++d) {
                digit = t % 10; t /= 10;
                for (int i : {-1, 1}) {
                    int dnext = (digit + i + 10) % 10;
                    int x = s + (dnext - digit) * dec[d];
                    if (!seen[x]) {
                        q.emplace(turn + 1, x);
                        seen[x] = 1;
                    }
                }
            }
        }
        return -1;
    }
};