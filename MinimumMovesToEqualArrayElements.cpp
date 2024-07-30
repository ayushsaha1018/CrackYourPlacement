// TC : O(n), SC : O(1)

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int st = 0, en = nums.size() - 1;
        int ans = 0;
        while(st < en){
            ans += nums[en] -  nums[st];
            st++;
            en--;
        }

        return ans;
    }
};