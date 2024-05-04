class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people), end(people));
        const int size = people.size();
        int ans = 0;
        for (int l = 0, r = size - 1; l <= r; --r) {
            ans++;
            l += (people[l] + people[r] <= limit);
        }
        return ans;
    }
};