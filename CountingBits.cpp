class Solution {
public:
    int solve(int i, vector<int> &dp){
        if(i == 0)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        return dp[i] = (i%2) + solve(i/2, dp);
    }

    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        vector<int> dp(n+1, -1);
        for(int i=0; i<=n; i++){
            ans[i] = solve(i, dp);
        }

        return ans;
    }
};