class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        const int size = deck.size();
        vector<int> ans(size);
        bool skip = false;
        int deckId = 0, ansId = 0;
        sort(deck.begin(), deck.end());

        while (deckId < size) {
            if (!ans[ansId]) {
                if (!skip)
                    ans[ansId] = deck[deckId++];
                skip = !skip;
            }
            ansId = (ansId + 1) % size;
        }
        return ans;
    }
};