class Solution {
public:
    struct doubleInt { int pos; int amount; };
    int firstUniqChar(string s) {
        unordered_map<char, doubleInt> ms;
        int i = 0;
        for (auto e : s)
        {
            ms[e].amount++;
            ms[e].pos = i++;
        }
        struct TripleVal { doubleInt mVal; char key; };
        vector<TripleVal> vec;
        for (auto e : ms)
        {
            TripleVal buf;
            buf.key = e.first;
            buf.mVal.amount = e.second.amount;
            buf.mVal.pos = e.second.pos;
            vec.push_back(buf);
        }
        sort(vec.begin(), vec.end(), [](TripleVal left, TripleVal right) {
            return left.mVal.pos < right.mVal.pos;
        });
        for (auto e : vec)
            if (e.mVal.amount == 1)
                return e.mVal.pos;
        return -1;
    }
};