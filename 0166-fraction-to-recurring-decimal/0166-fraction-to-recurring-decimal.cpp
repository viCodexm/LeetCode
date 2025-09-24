using ll = long long;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) {
            return "0";
        }
        string res;
        if ((numerator < 0) ^ (denominator < 0)) {
            res.push_back('-');
        }

        ll n = llabs((ll)numerator);
        ll d = llabs((ll)denominator);

        res += to_string(n / d);
        ll rem = n % d;
        if (!rem) {
            return res;
        }

        res.push_back('.');
        unordered_map<ll, int> seen;

        while (rem) {
            if (seen.find(rem) != seen.end()) {
                int pos = seen[rem];
                res.insert(pos, "(");
                res.push_back(')');
                break;
            }
            seen[rem] = res.size();
            rem *= 10;
            int digit = rem / d;
            res.push_back(char('0' + digit));
            rem = rem % d;
        }
        return res;
    }
};