// TC : O(nlogn), SC : O(n)

class Solution {
public:
    int merge(vector<int> &nums, int low, int mid, int high){
        int count = 0;
        int j = mid + 1;
        for(int i=low; i<= mid; i++){
            while(j <= high && nums[i] > 2LL*nums[j])
                j++;
            
            count += (j - (mid + 1));
        }

        vector<int> t;
        int i = low;
        j = mid + 1;
        while(i<= mid && j<=high){
            if(nums[i] <= nums[j]){
                t.push_back(nums[i]);
                i++;
            }
            else{
                t.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid){
            t.push_back(nums[i]);
            i++;
        }

        while(j <= high){
            t.push_back(nums[j]);
            j++;
        }

        for(int i=low; i<= high; i++){
            nums[i] = t[i-low];
        }

        return count;
    }

    int mergeSort(vector<int> &nums, int begin, int end){
        if(begin >= end)
            return 0;
        
        int mid = (begin + end)/2;
        int inv = mergeSort(nums, begin, mid);
        inv += mergeSort(nums, mid + 1, end);
        inv += merge(nums, begin, mid, end);

        return inv;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};