class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int v=0, c;
        for (auto i: nums){
            if (v==0)c = i;
            if (c==i)v++;
            else v--;
        }
        return c;
    }
};