class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ans(2);
        for(int i=0; i<size(nums); i++){
            if(hash.find(nums[i]) != hash.end()){
                ans[0] = hash[nums[i]];
                ans[1] = i;
                return ans;
            }
            hash[target-nums[i]] = i;
        }
    }
};
