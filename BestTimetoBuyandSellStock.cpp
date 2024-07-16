// TC : O(n), SC : O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = prices[0];
        int ans = 0;

        for(int i=1; i<n; i++){
            int profit = prices[i] - minPrice;
            ans = max(ans, profit);
            minPrice = min(minPrice, prices[i]);
        }

        return ans;
    }
};