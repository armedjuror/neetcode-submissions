class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(int i: nums){
            if (hash.find(i) == hash.end())hash[i]=0;
            hash[i]++;
        }
        vector<vector<int>> bucket(nums.size()+1);
        for(auto& [num, freq]: hash){
            bucket[freq].push_back(num);
        }

        int i=0;
        vector<int> result;
        for (int i = bucket.size() - 1; i >= 0 && (int)result.size() < k; i--)
        for (int num : bucket[i]) {
            result.push_back(num);
            if ((int)result.size() == k) return result; // early exit
        }
    }
};
