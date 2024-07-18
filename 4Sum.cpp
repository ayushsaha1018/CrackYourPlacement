// TC : O(n3), SC : O(n)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums,long long int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long long int t = target - nums[i] - nums[j];
                int l = j+1;
                int r = n-1;

                while(l<r){
                    int sum = nums[l] + nums[r];

                    if(sum > t){
                        r--;
                    }
                    else if(sum < t){
                        l++;
                    }
                    else{
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while(l < r && nums[l] == nums[l-1])
                            l++;
                        while(l < r && nums[r] == nums[r+1])
                            r--;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1])
                    j++;
            }
            while(i+1<n && nums[i] == nums[i+1])
                i++;
        }

        return ans;
    }
};