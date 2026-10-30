class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for( int s:stones){
            maxHeap.push(s);
        }
        int x, y;
        while(maxHeap.size() >= 2){
            x = maxHeap.top();maxHeap.pop();
            y = maxHeap.top();maxHeap.pop();
            if (y<x){
                maxHeap.push(x-y);
            }            
        }

        if (maxHeap.size()==1){
            return maxHeap.top();
        }else{
            return 0;
        }
    }
};
