// TC : O(nlogn), SC : O(n)

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        int n = points.size();
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            while(!pq.empty() && (points[i][0] - pq.top().second) > k)
                pq.pop();
            if(!pq.empty()){
                ans = max(ans, points[i][0] + points[i][1] + pq.top().first);
            }
            pq.push({points[i][1] - points[i][0], points[i][0]});
        }

        return ans;
    }
};