class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        		auto compare = [](const pair<int, int>& left, const pair<int, int>& right) {
			const double l1		 = ((double)left.first / left.second);
			const double l2		 = ((double)(left.first + 1) / (left.second + 1));
			const double lgrowth = l2 - l1;

			const double r1		 = ((double)right.first / right.second);
			const double r2		 = ((double)(right.first + 1) / (right.second + 1));
			const double rgrowth = r2 - r1;

			return lgrowth < rgrowth;
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq;
		const int n = classes.size();
		for (int i = 0; i < n; ++i) {
			pq.push({classes[i][0], classes[i][1]});
		}

		for (int i = 0; i < extraStudents; ++i) {
			pair<int, int> x = pq.top();
			pq.pop();
			pq.push({x.first + 1, x.second + 1});
		}
		double answer = 0;
		while (!pq.empty()) {
			const auto [x, y] = pq.top();
			answer += (double)x / y;
			pq.pop();
		}
		return answer / n;
    }
};