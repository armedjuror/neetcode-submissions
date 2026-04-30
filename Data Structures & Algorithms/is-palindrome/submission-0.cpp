class Solution {
public:
    bool isalnum(char c){
        if ((int(c) >= 65 && int(c) <= 91) || (int(c)>=97 && int(c) <= 123) || (int(c) >= 48 && int(c) <= 57)) return true;
        else return false;
    }

    string onlyAlphaNum(string s){
        string ps="";
        for(char c:s){
            if (isalnum(c)){
                ps+=tolower(c);
            }
        }
        return ps;
    }

    bool isPalindrome(string s) {
        string ps=onlyAlphaNum(s);
        int i, n=ps.length(), j=n-1;
        while(i<j){
            if (ps[i]!=ps[j]){
                return false;
            }
            i++;
            j=n-i-1;
        }
        return true;
    }
};
