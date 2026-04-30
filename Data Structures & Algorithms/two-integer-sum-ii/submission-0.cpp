class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i, n=numbers.size(), j;
        j = n-1;i=0;
        while(i<j){
            if(numbers[i]+numbers[j] == target)return vector<int> {i+1, j+1};
            else if(numbers[i]+numbers[j] > target)j--;
            else i++;
        }
    }
};
