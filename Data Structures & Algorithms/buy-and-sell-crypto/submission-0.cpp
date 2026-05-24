class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit {0};
        for (int x = 0; x < prices.size(); x++) {
            for (int y = x+1; y < prices.size(); y++) {
                if (prices[x] - prices[y] < 0) {
                    maxProfit = max(abs(prices[x] - prices[y]), maxProfit);
                }
            }
        }
        return maxProfit;
    }
};
