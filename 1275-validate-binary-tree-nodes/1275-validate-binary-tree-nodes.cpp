class Solution {
public:
    class DisjointSet {
    public:
        int components;
        int n;
        vector<int> parent;

        DisjointSet(int n) {
            this->n = components = n;
            parent.resize(n + 1);
            for (int i = 1; i <= n; ++i)
                parent[i] = i;
        }
        int getRep(int i) {
            if (parent[i] != i)
                parent[i] = getRep(parent[i]);
            return parent[i];
        }
        bool join(int u, int v) {
            int RepU = getRep(u);
            int RepV = getRep(v);
            if (RepV != v || RepU == RepV)
                return false;
            
            components--;
            parent[RepV] = RepU;
            return true;
        }
    };
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DisjointSet ds(n);
        for (int i = 0; i < n; ++i) {
            auto children = { leftChild[i], rightChild[i] };
            for (int child : children) {
                if (child == -1)
                    continue;
                if (!ds.join(i, child))
                    return false;
            }
        }
        return ds.components == 1;
    }
};