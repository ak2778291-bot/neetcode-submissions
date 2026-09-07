class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0;
        int profit = 0;
        for(int buy = 0; buy < n; buy++){
            int sell = buy+1;
           while (n > sell){
            if (prices[buy] > prices[sell]){
            }
            else{
               profit = prices[sell] - prices[buy];
               maxi = max (profit, maxi);
               }
               sell+=1;
        }
        }
        return maxi;
    }
};
