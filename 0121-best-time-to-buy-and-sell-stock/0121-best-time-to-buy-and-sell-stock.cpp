class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        
        vector<int> minPricesSoFar;
        int currentMin = prices[0];
        
        for (int i = 0; i < n; i++) {
            if (prices[i] < currentMin) {
                currentMin = prices[i];
            }
            minPricesSoFar.push_back(currentMin);
        }
        
        vector<int> maxProfitEachDay;
        
        for (int i = 0; i < n; i++) {
            int buyPrice = minPricesSoFar[i];
            int sellPrice = prices[i];
            int profit = sellPrice - buyPrice;
            maxProfitEachDay.push_back(profit);
        }
        
        int finalMaxProfit = 0;
        
        for (int i = 0; i < maxProfitEachDay.size(); i++) {
            if (maxProfitEachDay[i] > finalMaxProfit) {
                finalMaxProfit = maxProfitEachDay[i];
            }
        }
        
        return finalMaxProfit;
    }
};