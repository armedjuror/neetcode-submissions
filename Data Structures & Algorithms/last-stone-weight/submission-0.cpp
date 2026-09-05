class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(auto s: stones){
            maxHeap.push(s);
        }
        // [2,3,6,2,4]
        // x=6, y=4
        // [2,3,2,2]
        // x = 3, y=2
        // [2,1,2]
        // x = 2, y=2
        // [1]
        // x= 1, y=-1

        while(maxHeap.size()>0){
            int x, y=-1;
            x = maxHeap.top();maxHeap.pop();
            if (maxHeap.size()>0){y = maxHeap.top();maxHeap.pop();}
            if (y == -1 and maxHeap.size()==0)return x;
            if (y < x)maxHeap.push(x-y);            
        }
        return 0;
    }
};
