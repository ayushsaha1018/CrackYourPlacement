// TC : O(n), SC : O(n)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> st;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(st.find(nums[i]) == st.end()){
                st.insert(nums[i]);
                nums[cnt] = nums[i];
                cnt++;
            }
        }

        return cnt;
    }
};
