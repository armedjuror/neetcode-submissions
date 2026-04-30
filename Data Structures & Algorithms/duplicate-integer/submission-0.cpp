class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> hash;
        for(int i: nums){
            if (hash.find(i)!=hash.end()){
                return true;
            }
            hash[i] = true;
        }
        return false;
    }
};