class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>> minHeap;
        int i = 0;
        for (auto p: points){
            float d = sqrt((p[0]*p[0])+(p[1]*p[1]));
            cout << "X=" << p[0] << ", Y=" << p[1] << ", Distance = " << 
            d << "\n";
            minHeap.push({d, i});
            i++;
        }
        vector<vector<int>> result;
        while(k-- && !minHeap.empty()){
            auto tp = minHeap.top();
            minHeap.pop();
            result.push_back(points[tp.second]);
        }
        return result;
    }
};
