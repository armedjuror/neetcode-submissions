class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int n: nums){
            if (freq.find(n)==freq.end())freq[n]=0;
            freq[n]++;
            if (freq[n]>1)return true;
        }
        return false;
    }
};