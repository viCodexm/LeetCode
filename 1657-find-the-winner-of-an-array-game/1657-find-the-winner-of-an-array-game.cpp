class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
			if (k >= arr.size())
			return *max_element(arr.begin(), arr.end());
        queue<int> q;
        for (int& e : arr)
            q.push(e);

		int winner = q.front(); q.pop();
		int sequence = 0;
        while (true) {
			while (winner > q.front() && sequence < k) {
				sequence++;
				q.push(q.front()); q.pop();
			}
			if (sequence >= k)
				return winner;
			else {
				q.push(winner);
				winner = q.front(); q.pop();
				sequence = 1;
			}
		}
		return -1;
    }
};