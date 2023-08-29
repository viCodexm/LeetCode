class Solution {
public:
    int bestClosingTime(string customers) {
        int result = 0, balance = 0, i = 0;
        for (char& c : customers) {

            if (c == 'N')
                balance++;
            else {
                balance--;
                if (balance < 0)
                {
                    result = i + 1;
                    balance = 0;
                }
            }
            i++;
        }
        return result;
    }
};
