class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> char_list;
        for (char c: s){
            if (char_list.find(c) == char_list.end())char_list[c] = 0;
            char_list[c]++;
        }
        for (char c: t){
            if (char_list.find(c)==char_list.end()) return false;
            char_list[c]--;
        }
        for(auto& p:char_list){
            if (p.second != 0)return false;
        }
        return true;
    }
};
