// TC : O(n), SC : O(n)


class Solution {
public:
    int solve(vector<int>& prices, int i, int buy, vector<vector<int>> &dp){
        if(i >= prices.size())
            return 0;
        
        if(buy){
            return max(+prices[i] + solve(prices, i+1, 0, dp), solve(prices, i+1, 1, dp));
        }
        else{
            return max(-prices[i] + solve(prices, i+1, 1, dp), solve(prices, i+1, 0, dp));
        }
    }

    int solveTab(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(prices.size()+1, vector<int> (3, 0));

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                if(buy){
                    dp[i][buy] = max( prices[i] + dp[i+1][0], dp[i+1][1]);
                }
                else{
                    dp[i][buy] = max(-prices[i] + dp[i+1][1], dp[i+1][0]);
                }
            }
        }

        return dp[0][0];
    }

    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size()+1, vector<int> (3, -1));
        // return solve(prices, 0, 0, dp);

        return solveTab(prices);
    }
};