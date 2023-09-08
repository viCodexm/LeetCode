class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1)
            return {{1}};
        vector<vector<int>> triangle = {{1}, {1, 1}};
        for (int i = 1; i < numRows - 1; ++i) {
            int size = triangle.back().size();
            int idx = triangle.size() - 1;
            
            triangle.push_back({});
            vector<int>& back = triangle.back();
            back.push_back(1);
            for (int j = 0; j < size - 1; ++j)
                back.push_back(triangle[idx][j] + triangle[idx][j + 1]);
            back.push_back(1);
        }

        return triangle;
    }
};