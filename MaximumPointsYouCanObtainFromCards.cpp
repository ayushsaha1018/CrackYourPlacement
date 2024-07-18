// TC : O(n), SC : O(1)

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int totalPoints = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int ans = 0;
        int windowSize = n - k;
        int sum = 0;
        for(int i = 0; i<windowSize; i++){
            sum += cardPoints[i];
            ans += cardPoints[i];
        }

        ans = max(0, totalPoints - sum);

        for(int i=windowSize; i<n; i++){
            sum -= cardPoints[i-windowSize];
            sum += cardPoints[i];

            ans = max(ans, totalPoints - sum);
        }

        return ans;

    }
};