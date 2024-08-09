class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;

        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        for(auto x : mp){
            pq.push({x.second, x.first});
        }
        
        vector<int> ans;
        while(!pq.empty() && k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};