class Graph {
public:
    vector<vector<pair<int, int>>> adjList;
    Graph(int n, vector<vector<int>>& edges) {
        adjList.resize(n);
        for (auto& e: edges)
            adjList[e[0]].push_back({e[1], e[2]});
    }

    void addEdge(vector<int> edge) {
        adjList[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2) {
        const int n = adjList.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> costForNode(n, INT_MAX);
        costForNode[node1] = 0;
        pq.push({0, node1});

        while (!pq.empty()) {
            const int currCost = pq.top()[0];
            const int currNode = pq.top()[1];
            pq.pop();

            if (currCost > costForNode[currNode]) {
                continue;
            }
            if (currNode == node2) {
                return currCost;
            }
            for (auto& neighbor : adjList[currNode]) {
                const int neighborNode = neighbor.first;
                const int cost = neighbor.second;
                const int newCost = currCost + cost;

                if (newCost < costForNode[neighborNode]) {
                    costForNode[neighborNode] = newCost;
                    pq.push({newCost, neighborNode});
                }
            }
        }
        return -1;
    }
};