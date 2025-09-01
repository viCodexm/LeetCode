class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        auto gain = [](int pass, int total) {
            return ((double)pass + 1) / (total + 1) - ((double)pass / total);
		};
		const int n = classes.size();
		for (int i = 0; i < n; ++i) {
			pq.push({gain(classes[i][0], classes[i][1]), i});
		}

		for (int i = 0; i < extraStudents; ++i) {
			const auto [profit, idx] = pq.top();
			pq.pop();
            classes[idx][0]++;
            classes[idx][1]++;
			pq.push({gain(classes[idx][0], classes[idx][1]), idx});
		}
		double answer = 0;
		for (const vector<int>& room : classes) {
			answer += (double)room[0] / room[1];
		}
		return answer / n;
    }
};