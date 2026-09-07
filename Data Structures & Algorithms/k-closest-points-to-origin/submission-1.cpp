class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, vector<int>>,
            vector<pair<long long, vector<int>>>,
            greater<pair<long long, vector<int>>>
        > minHeap;
        for (auto point:points){
            minHeap.push({(point[0]*point[0])+(point[1]*point[1]), point});
        }
        vector<vector<int>> kClosestPoints;
        for (int i=0; i< k; i++){
            pair<long long, vector<int>> p = minHeap.top();
            kClosestPoints.push_back(p.second);
            minHeap.pop();
        }
        return kClosestPoints;
    }
};
