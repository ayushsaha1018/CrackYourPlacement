// TC : O(n), SC : O(n)

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.length();

        string temp = "";
        int i = 0;
        while(i < n){
            while(i < n && s[i] != ' '){
                temp += s[i];
                i++;
            }
            
            if(temp.length() > 0)
                ans = temp + " " + ans;
            temp = "";
            i++;
        }

        if(temp.length() > 0)
            ans += temp;
        
        ans.pop_back();
        return ans;
    }
};