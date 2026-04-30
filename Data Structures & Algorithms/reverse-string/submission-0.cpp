class Solution {
public:
    void reverseString(vector<char>& s) {
        int i,j , n=size(s);
        for (i=0; i<j; i++){
            j=n-i-1;
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
        }
    }
};