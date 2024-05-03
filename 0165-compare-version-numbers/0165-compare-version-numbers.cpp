class Solution {
public:
    int compareVersion(string v1, string v2) {
        stringstream s1(move(v1)), s2(move(v2));
        string token1, token2;
        while (getline(s1, token1, '.') && getline(s2, token2, '.')) {
            int n1 = stoi(token1), n2 = stoi(token2);
            token1 = token2 = "";
            if (n1 == n2)
                continue;
            return (n1 > n2) ? 1 : -1;
        }
        
        do if (!token1.empty() && stoi(token1) > 0) return  1; while (getline(s1, token1, '.'));
        do if (!token2.empty() && stoi(token2) > 0) return -1; while (getline(s2, token2, '.'));

        return 0;
    }
};