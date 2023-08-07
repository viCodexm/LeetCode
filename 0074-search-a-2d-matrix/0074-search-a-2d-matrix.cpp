class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // find line
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n - 1;
        int border_val = m - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid][0] <= target && target <= matrix[mid][border_val])
                l = r = mid;
            else if (target > matrix[mid][border_val])
                l = mid + 1;
            else r = mid - 1;
        }
        int foundI = l;
        // find value
        l = 0, r = m - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (matrix[foundI][mid] == target)
                return true;
            if (matrix[foundI][mid] > target)
                r = mid - 1;
            else l = mid + 1;
        }
        return matrix[foundI][l] == target;
    }
};