class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i: nums){
            maxHeap.push(i);
        }
        n = k;
    }
    
    int add(int val) {
        maxHeap.push(val);
        vector<int> rem;
        int r;
        for(int i=1; i<=n; i++){
            r = maxHeap.top();
            maxHeap.pop();
            rem.push_back(r);
        }
        for(int i: rem){
            maxHeap.push(i);
        }
        return r;
    }

private:
    priority_queue<int> maxHeap;
    int n;
};
