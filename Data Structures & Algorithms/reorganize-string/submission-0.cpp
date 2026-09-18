class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        int maxFreq=0;
        for(auto c:s){
            freq[c-'a']++;
        }
        for(auto f:freq){
            if (f>maxFreq)maxFreq=f;
        }
        if (maxFreq > (n+1)/2)return "";

        priority_queue<pair<int, char>> maxHeap;
        for (int i=0; i<26; i++){
            if (freq[i]>0){
                maxHeap.push({freq[i], (char)('a'+i)});
            }
        }

        string result;
        result.reserve(n);
        while(maxHeap.size()>=2){
            auto [f1, c1] = maxHeap.top();maxHeap.pop();
            auto [f2, c2] = maxHeap.top();maxHeap.pop();
            result += c1;
            result += c2;
            if(--f1 > 0)maxHeap.push({f1, c1});
            if(--f2 > 0)maxHeap.push({f2, c2});
        }

        if (!maxHeap.empty()) {
            auto [f1, c1] = maxHeap.top();maxHeap.pop();
            result += c1;
        }
        
        return result;
    }
};