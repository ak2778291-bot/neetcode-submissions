class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left = 0, right = 1, maxProfit = 0;
        while (right < n){
            if (prices[left] < prices[right]){
                int profit = prices[right] - prices[left];
                maxProfit = max(profit, maxProfit);
            }
            else{
            left = right;
            }
            right += 1;
        }
        return maxProfit;
    }
};
