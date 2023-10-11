class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        sort(flowers.begin(), flowers.end());
        vector<int> sortedPeople(people.begin(), people.end());
        sort(sortedPeople.begin(), sortedPeople.end());

        unordered_map<int, int> dict;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int i = 0;
        const int flsize = flowers.size();
        for (int& person : sortedPeople) {
            while (i < flsize && flowers[i][0] <= person) {
                pq.push(flowers[i][1]);
                i++;
            }
            while (!pq.empty() && pq.top() < person)
                pq.pop();

            dict[person] = pq.size();
        }
        vector<int> ans;
        for (int& person : people)
            ans.push_back(dict[person]);
        return ans;
    }
};