// TC : O(nlogn), SC : O(nlogn)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m;i<=m+n-1;i++)
        {
            nums1[i] = nums2[i-m];
        }
        sort(nums1.begin(),nums1.end());    
    }
};