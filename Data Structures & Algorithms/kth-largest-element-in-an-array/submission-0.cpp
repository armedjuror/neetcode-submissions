class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        for (auto n: nums){
            maxHeap.push(n);
        }
        k--;
        while(k--){
            maxHeap.pop();
        }
        return maxHeap.top();
    }
};
