class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int maxi = INT_MIN;
        int bestBuy = prices[0];

        for(int i=0;i<n;i++)
        {
            int profit = prices[i] - bestBuy;

            if(profit < 0)
                bestBuy = prices[i];

            maxi = max(maxi,profit);
        }

        return maxi;
    }
};
