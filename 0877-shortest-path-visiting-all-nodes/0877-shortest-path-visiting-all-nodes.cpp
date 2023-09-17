class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int allVisitedMask = (1 << n) - 1;
        queue<tuple<int, int, int>> q;

        bool visited[allVisitedMask + 1][n];
        memset(visited, false, sizeof visited);

        for (int node = 0; node < n; ++node) {
            int initialMask = (1 << node);
            q.push({node, initialMask, 1});
            visited[initialMask][node] = true;
        }

        while (!q.empty()) {
            int currentNode, currentMask, currentLength;
            tie(currentNode, currentMask, currentLength) = q.front();
            q.pop();

            if (currentMask == allVisitedMask)
                return currentLength - 1;

            for (int i = 0; i < graph[currentNode].size(); ++i) {
                int neighbor = graph[currentNode][i];
                int newMask = currentMask | (1 << neighbor);

                if (visited[newMask][neighbor])
                    continue;

                q.push({neighbor, newMask, currentLength + 1});
                visited[newMask][neighbor] = true;
            }
        }
        return -1;
    }
};