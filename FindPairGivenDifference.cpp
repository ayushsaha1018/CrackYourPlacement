// TC : O(nlogn), SC : O(n)

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            int target = arr[i] - x;
            if(mp.find(target) != mp.end())
                return 1;
            mp[arr[i]]++;
        }
        
        return -1;
    }
};