// TC : O(n), SC : O(n)

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        unordered_map<string, vector<string>> mp;
        
        int n = string_list.size();
        for(int i=0; i<n; i++){
            string t = string_list[i];
            sort(t.begin(), t.end());
            mp[t].push_back(string_list[i]);
        }
        
        vector<vector<string>> res;
        for(auto x : mp){
            res.push_back(x.second);
        }
        
        return res;
    }
};