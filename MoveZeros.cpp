// TC : O(n), SC : O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        while(r < n){
            if(nums[r] != 0){
                swap(nums[l], nums[r]);
                l++;
                r++;
            }
            else{
                r++;
            }
        }
    }
};