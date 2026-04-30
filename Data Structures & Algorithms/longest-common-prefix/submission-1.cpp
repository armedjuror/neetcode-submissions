class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unordered_map<string, int> h;
        int n = size(strs);
        for (string s: strs){
            string p="";
            for (char c: s){
                p += c;
                if (h.find(p)==h.end())h[p]=0;
                h[p]++;
            }
        }
        string lcp="";
        for (auto& it: h){
            if (it.second == n){
                if (lcp.length() < it.first.length())lcp = it.first;
            }
        }
        return lcp;
    }
};