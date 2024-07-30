// TC : O(n), SC : O(1)

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        int n = s.length();

        for(int i=0; i<t.length(); i++)
            mp[t[i]]++;
        
        int cntReq = t.length();
        
        int i=0, j = 0;
        int minStart = 0, minLength = INT_MAX;
        while(j < n){
            char ch = s[j];
            if(mp[ch] > 0)
                cntReq--;
            
            mp[ch]--;

            while(cntReq == 0){
                if(minLength > (j-i+1)){
                    minStart = i;
                    minLength = j-i + 1;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0)
                    cntReq++;
                i++;
            }
            j++;
        }

        if(minLength == INT_MAX)
            return "";
        
        return s.substr(minStart, minLength);
    }
};