class Solution {
public:
    bool isPalindrome(string s, int rem){
        cout << s << " " << rem << endl;
        int i=0,j=s.length()-1, n=s.length();
        while(i<j){
            if (s[i]==s[j]){
                i++;
                j--;
            }else{
                if (rem+1 <= 1) return (isPalindrome(s.substr(i+1, j-i), rem+1) || isPalindrome(s.substr(i, j-i), rem+1));
                else return false;
            }
        }
        return rem<=1;
    }

    bool validPalindrome(string s) { 
        return isPalindrome(s, 0);
    }
};