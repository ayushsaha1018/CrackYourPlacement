// TC : O(log n), SC : O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, en = nums.size() -1;

        while(st <= en){
            int mid = (st + en)/2;

            if(nums[mid] == target)
                return mid;
            
            // left sorted
            if(nums[st] <= nums[mid]){
                if(nums[st] <= target && target < nums[mid]){
                    en = mid - 1;
                }
                else{
                    st = mid + 1;
                }
            }
            else{
                if(nums[mid] < target && target <= nums[en]){
                    st = mid + 1;
                }
                else{
                    en = mid - 1;
                }
            }
        }

        return -1;
    }
};