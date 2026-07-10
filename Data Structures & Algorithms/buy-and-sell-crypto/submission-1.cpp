class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buy = prices[0];
        int maxP = 0;

        for (int p : prices) {
            maxP = max(maxP, p - min_buy);
            min_buy = min(min_buy, p);
        }
        return maxP;
    }
};
