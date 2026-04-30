class Solution {
public:
    void merge(vector<int>& arr, int l, int m, int r){
        vector<int> left(arr.begin()+l, arr.begin()+m+1);
        vector<int> right(arr.begin()+m+1, arr.begin()+r+1);
        int i=0, j=0, k=l;
        while(i<left.size() && j < right.size()){
            arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
        }
        while(i<left.size())arr[k++] = left[i++];
        while(j<right.size())arr[k++] = right[j++];
    }

    void mergeSort(vector<int>& arr, int l, int r){
        if (l >= r)return;
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};