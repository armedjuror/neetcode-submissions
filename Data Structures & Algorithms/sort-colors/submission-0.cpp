class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        for(int i:nums){
            count[i]++;
        }
        int j=0;
        for(int i=0; i<3; i++){
            while(count[i]){
                nums[j++] = i;
                count[i]--;
            }
        }
    }
};