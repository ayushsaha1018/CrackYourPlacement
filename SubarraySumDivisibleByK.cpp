// TC : O(n), SC : O(n)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        int ans = 0;

        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i=0; i<n; i++){
            sum += nums[i];
            int rem = sum % k;
            if(rem < 0){
                rem += k;
            }

            if(mp.find(rem) != mp.end())
                ans += mp[rem];
            
            mp[rem]++;
        }

        return ans;
    }
};