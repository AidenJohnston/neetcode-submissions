class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit {0};
        int lowestPrice {INT_MAX};
        for (int x = 0; x < prices.size(); x++) {
            lowestPrice = min(prices[x], lowestPrice);
            maxProfit = max((prices[x] - lowestPrice), maxProfit);
        }
        return maxProfit;
    }
};
