class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (auto s: strs){
            res += std::to_string(s.length()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int n=s.size(), i=0; 
        while(i<n){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int l = stoi(s.substr(i, j-i));
            strs.push_back(s.substr(j+1, l));
            i=j+l+1;
        }
        return strs;
    }
};
