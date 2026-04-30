class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int count=0, l=0, n=size(nums);
        // l = n;
        // for (int i=0; i < n;i++){
        //     if(nums[i]==val){
        //         count++;
        //         l--;
        //         while(l>0){
        //             if (nums[l]!=val){
        //                 nums[i] = nums[l];
        //                 break;
        //             }
        //             l--;
        //         }
        //     }
        // }
        // return n-count;
        int n = size(nums), k=0;
        for(int i=0; i<n; i++){
            if (nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};