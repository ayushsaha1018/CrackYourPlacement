// TC : O(n), SC : O(n)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        int n = strs.size();

        for(int i=0; i<n; i++){
            string t = strs[i];
            sort(t.begin(), t.end());
            mp[t].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for(auto x : mp){
            res.push_back(x.second);
        }

        return res;
    }
};