class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        int second_slow = 0;
        bool loop = false;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (loop) second_slow = nums[second_slow];
            loop = loop || slow == fast;
            if (slow == second_slow) return slow;
        }
    }
};