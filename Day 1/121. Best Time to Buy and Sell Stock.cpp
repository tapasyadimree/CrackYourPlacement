class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int miniCost = prices[0];
        int maxi = INT_MIN;

        for(int i = 1; i < prices.size(); i++){
            int todayProfit = (prices[i] - miniCost);
            maxi = max(maxi, todayProfit);
            miniCost = min(prices[i], miniCost);
        }

        if(maxi < 0) return 0;
        return maxi;
    }
};