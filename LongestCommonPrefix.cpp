// TC : O(n2), SC : O(n)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        sort(strs.begin(), strs.end(),
             [](const std::string& first, const std::string& second) {
                 return first.size() < second.size();
             });
            
        for(int i=0; i<strs[0].size(); i++){
            char c = strs[0][i];
            for(int j=1; j<n; j++){
                if(strs[j][i] != c)
                    return ans;
            }
            ans += c;
        }

        return ans;
    }
};