class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> answer;
		deque<int> dq;
		int n = nums.size();
		int l = 0, r = 0;
		while (r < n) {
			
			while (!dq.empty() && nums[dq.back()] < nums[r])
				dq.pop_back();
			dq.push_back(r);

			if (l > dq.front())
				dq.pop_front();

			if (r + 1 >= k) {
				answer.push_back(nums[dq.front()]);
				l++;
			}
			r++;
		}

		return answer;
	}
};