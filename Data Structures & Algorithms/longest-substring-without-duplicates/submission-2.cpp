class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> cs;int l=0, r=0, ms=0;
        for(; r < s.length(); r++){
            while (cs.find(s[r])!=cs.end()){cs.erase(s[l]);l++;}
            cs.insert(s[r]);
            ms = ms>r-l+1?ms:r-l+1;
        }
        return ms;
    }
};
