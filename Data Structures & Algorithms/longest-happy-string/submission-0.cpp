class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap;
        if (a > 0) maxHeap.push({a, 'a'});
        if (b > 0) maxHeap.push({b, 'b'});
        if (c > 0) maxHeap.push({c, 'c'});
        string result="";
        result.reserve(a+b+c);

        int ccf = 0;char lc;
        while(!maxHeap.empty()){
            auto [freq, let] = maxHeap.top();maxHeap.pop();
            int n = result.size();
            if (n >= 2 && result[n-1] == result[n-2] && result[n-1] == let) {
                if (maxHeap.empty()) {
                    break;
                }
                auto [freq2, let2] = maxHeap.top();
                maxHeap.pop();

                result += let2;
                if (--freq2 > 0) maxHeap.push({freq2, let2});
                maxHeap.push({freq, let});
            }else{
                result += let;
                if (--freq > 0)maxHeap.push({freq, let});
            }
        }
        return result;
    }
};