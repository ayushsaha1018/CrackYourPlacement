// TC : O(n*n!), SC : O(n2)

class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
       sort(arr.begin(), arr.end());
       
       set<vector<int>> st;
       do{
           st.insert(arr);
       } while (next_permutation(arr.begin(), arr.end())); 
       
       vector<vector<int>> ans(st.begin(), st.end());
       
       return ans;
       
    }
};