class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int l = 0;
        if (!left.empty())
            l = *max_element(left.begin(), left.end());
        
        int r = n;
        if (!right.empty())
            r = *min_element(right.begin(), right.end());

        int ans = max(l, n - r);
        return ans;
    }
};