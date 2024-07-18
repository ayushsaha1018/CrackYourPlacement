// TC : O(n), SC : O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int l = 0, r = n-1;

        while(l<r){
            ans = max(ans, min(height[l], height[r]) * (r-l));
            if(height[r] > height[l])
                l++;
            else
                r--;
        }

        return ans;
    }
};