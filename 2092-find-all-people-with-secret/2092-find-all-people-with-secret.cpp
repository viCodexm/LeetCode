struct DisjointSet {
    vector<int> parent;

	DisjointSet(int n) {
		parent.resize(n);
		for (int i = 0; i < n; ++i)
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
    void resetNode(int x) {
        parent[x] = x;
    }
    bool connected(int x, int y) {
        return getRep(x) == getRep(y);
    }
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        map<int, vector<pair<int, int>>> layers;
        for (const vector<int>& meet : meetings)
            layers[meet[2]].push_back({meet[0], meet[1]});
        
        DisjointSet ds(n);
        ds.join(0, firstPerson);
        int secret = ds.getRep(0);
        
        for (const auto& [time, meetings] : layers) {
            for (auto& [x, y] : meetings)
                ds.join(x, y);
            for (auto& [x, y] : meetings)
                if (!ds.connected(x, secret)) {
                    ds.resetNode(x);
                    ds.resetNode(y);
                }
        }

        
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (ds.connected(i, secret))
                ans.push_back(i);
        
        return ans;
    }
};