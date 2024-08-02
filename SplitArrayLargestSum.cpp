// TC : O(nlog n), SC : O(1)

class Solution {
public:
    int noOfSubarrays(vector<int>& nums, int mid){
        int cnt = 1;
        int currSum = 0;
        for(int i=0; i<nums.size(); i++){
            if(currSum + nums[i] > mid){
                cnt++;
                currSum = nums[i];
            }
            else{
                currSum += nums[i];
            }
        }

        return cnt;
    }

    int splitArray(vector<int>& nums, int k) {
        int st = *max_element(nums.begin(), nums.end());
        int en = accumulate(nums.begin(), nums.end(), 0);

        while(st <= en){
            int mid = (st + en)/2;
            int cnt = noOfSubarrays(nums, mid);

            if(cnt > k){
                st = mid + 1;
            }
            else{
                en = mid - 1;
            }
        }

        return st;
    }
};