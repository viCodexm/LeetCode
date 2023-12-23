class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        set<pair<int, int>> st; st.insert({0, 0});
        for (char& c : path) {
            switch (c) {
            case 'N':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'S':
                y++;
                break;
            case 'W':
                x--;
                break;
            }
            if (st.contains({x, y}))
                return true;
            st.insert({x, y});
        }
        return false;
    }
};