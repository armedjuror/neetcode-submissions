class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans_map;
        for(auto s: strs){
            string key = s;
            sort(key.begin(), key.end());
            ans_map[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it:ans_map){
            ans.push_back(it.second);
        }
        return ans;
    }
};
