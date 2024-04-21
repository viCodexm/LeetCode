class Solution {
public:
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);
        for (vector<int>& e : edges)
            ds.join(e[0], e[1]);
        return ds.getRep(source) == ds.getRep(destination);
    }

};