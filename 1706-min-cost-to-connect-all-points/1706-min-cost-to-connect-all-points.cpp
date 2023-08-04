class DisjointSet {
public:
	vector<int> parent;

	DisjointSet(int n) {
		parent.resize(n + 1);
		for (int i = 1; i <= n; ++i)
			parent[i] = i;
	}
	int getRep(int i) {
		if (parent[i] != i)
			parent[i] = getRep(parent[i]);
		return parent[i];
	}
	void join(int u, int v) {
		int RepU = getRep(u);
		int RepV = getRep(v);
		if (RepU == RepV) return;
		if (rand() % 2)
			parent[RepU] = RepV;
		else parent[RepV] = RepU;
	}
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& pts) {
        struct ftw {
		    int from, to, weight;
	    };
        int n = pts.size();
        DisjointSet ds(n);
        vector<ftw> input;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(pts[i][0] - pts[j][0]) + abs(pts[i][1] - pts[j][1]);
                input.push_back({i, j, dist});
                input.push_back({j, i, dist});
            }
        sort(input.begin(), input.end(), [](const ftw& left, const ftw& right) {
		    return left.weight < right.weight;
		});
        int totalWeight = 0;
        for (ftw& edge : input) {
            int from = edge.from;
            int to = edge.to;
            int weight = edge.weight;

            if (ds.getRep(from) != ds.getRep(to)) {
                ds.join(from, to);
                totalWeight += weight;
            }
        }
        return totalWeight;
    }
};