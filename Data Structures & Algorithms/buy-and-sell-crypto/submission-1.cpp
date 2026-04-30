class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b = 0, max_profit = 0;
        for (int s=0; s< prices.size(); s++){
            if (prices[b] > prices[s])b=s;
            else{
                int p = prices[s] - prices[b];
                max_profit = max(max_profit, p);
            }
        }
        return max_profit;
    }
};
