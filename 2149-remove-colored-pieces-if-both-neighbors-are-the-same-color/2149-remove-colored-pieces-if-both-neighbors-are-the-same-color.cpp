class Solution {
public:
    bool winnerOfGame(string colors) {
        const int size = colors.size();
        int a = 0, b = 0;
        for (int i = 0; i < size; ++i) {
            if (colors[i] == colors[i + 1] && colors[i] == colors[i + 2])
            {
                if (colors[i] == 'A')
                    a++;
                else b++;
            }
        }
        return a > b;
    }
};