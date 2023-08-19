class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int getRep(int i) {
        if (parent[i] != i)
            parent[i] = getRep(parent[i]);
        return parent[i];
    }
    bool join(int u, int v) {
        int repu = getRep(u);
        int repv = getRep(v);
        if (repu == repv)
            return false;

        if (size[repu] < size[repv]) {
            parent[repu] = repv;
            size[repv] += size[repu];
        }
        else {
            parent[repv] = repu;
            size[repu] += size[repv];
        }
        return true;
    }
    int getSize(int x) {
        return size[getRep(x)];
    }
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        int m = edges.size();
        for (int i = 0; i < m; ++i)
            edges[i].push_back(i);

        sort(edges.begin(), edges.end(), [](const vector<int>& left, const vector<int>& right) {
		    return left[2] < right[2];
		});

        DisjointSet ds(n);
        int mstWeight = 0;
        for (int i = 0; i < m; ++i)
            if (ds.join(edges[i][0], edges[i][1]))
                mstWeight += edges[i][2];
        
        vector<int> critical, pscritical;
        for (int i = 0; i < m; ++i) {
            DisjointSet tempDS(n);
            int weightWithout = 0;
            for (int j = 0; j < m; ++j)
                if (i != j && tempDS.join(edges[j][0], edges[j][1]))
                    weightWithout += edges[j][2];
            
            if (tempDS.getSize(0) != n || weightWithout > mstWeight)
                critical.push_back(edges[i][3]);
            else {
                DisjointSet newDS(n);
                newDS.join(edges[i][0], edges[i][1]);
                int weightWith = edges[i][2];
                for (int j = 0; j < m; ++j)
                    if (i != j && newDS.join(edges[j][0], edges[j][1]))
                        weightWith += edges[j][2];

                if (weightWith == mstWeight)
                    pscritical.push_back(edges[i][3]);
            }
        }
        return {critical, pscritical};
    }
};