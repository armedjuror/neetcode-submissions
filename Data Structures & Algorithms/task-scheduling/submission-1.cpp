class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // vector<int> freq(26, 0);
        // for (auto t: tasks){
        //     freq[t - 'A']++;
        // }
        // int maxFreq=0;
        // for (auto f: freq){
        //     maxFreq = max(maxFreq, f);
        // }
        // int maxCount = 0;
        // for (int f:freq){
        //     if (f==maxFreq)maxCount++;
        // }
        // return max((int)tasks.size(), (maxFreq-1)*(n+1)+maxCount);

        vector<int> freq(26, 0);
        for (auto t: tasks){
            freq[t - 'A']++;
        }
        priority_queue<int> maxHeap;
        for (int f: freq){
            if (f>0)maxHeap.push(f);
        }

        int time = 0;
        queue<pair<int, int>> cooldown;
        while(!maxHeap.empty() || !cooldown.empty()){
            time++;
            if (!maxHeap.empty()){
                int count = maxHeap.top()-1;
                maxHeap.pop();
                if (count>0){
                    cooldown.push({count, time+n});
                }
            }

            if (!cooldown.empty() && cooldown.front().second == time){
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }
        return time;
    }
};
