class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
		for (int i = nums.size(); i != 0; --i){
			while (nums[i-1] <= size && nums[i-1] >= 1 && nums[i-1] != i && nums[nums[i-1] - 1] != nums[i-1])
		        swap(nums[i-1], nums[nums[i-1] - 1]);
        	if (nums[i-1] != i)
        		size = i-1;
		}
		return size + 1;
    }
};