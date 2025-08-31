class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        const int offset = 5e4;
        const int size = 1e5 + 1;
        int bucket[size];
        memset(bucket, 0, sizeof(bucket));
        for (const int num : nums) {
            bucket[offset + num]++;
        }

        vector<int> answer;
        answer.reserve(nums.size());
        for (int i = 0; i < size; ++i) {
            if (!bucket[i]) {
                continue;
            }
            answer.insert(answer.end(), bucket[i], i - offset);
        }
        return answer;
    }
};