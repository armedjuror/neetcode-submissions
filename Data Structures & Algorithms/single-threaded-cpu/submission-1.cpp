class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size(), j=0;// pointer into sorted tasks
        long long time = 0;
        vector<array<int, 3>> t(n);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minHeap;

        for (int i = 0; i < n; i++){
            t[i] = {tasks[i][0], tasks[i][1], i};
        }
        sort(t.begin(), t.end());

        vector<int> result;
        result.reserve(n);

        while(result.size() < n){
            while (j < n && t[j][0] <= time){
                minHeap.push({t[j][1], t[j][2]});
                j++;
            }

            if (minHeap.empty()){
                time = t[j][0];
                continue;
            }

            auto [proc, idx] = minHeap.top();
            minHeap.pop();
            time += proc;
            result.push_back(idx);
        }
        return result;
    }
};