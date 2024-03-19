class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> w(26);
        for (char& task : tasks)
            w[task - 'A']++;

        priority_queue<int> pq;
        for (int& e : w)
            if (e)
                pq.push(e);

        int time = 0;
        queue<pair<int, int>> await;
        while (!pq.empty() || !await.empty()) {
            time++;
            if (!pq.empty()) {
                if (pq.top() - 1)
                    await.push({pq.top() - 1, time + n});
                pq.pop();
            }

            if (!await.empty() && await.front().second <= time) {
                pq.push(await.front().first);
                await.pop();
            }
        }
        return time;
    }
};