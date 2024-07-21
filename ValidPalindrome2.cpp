// TC : O(n), SC : O(1)

class Solution {
public:
    bool check(string &s, int st, int en){
        while(st < en){
            if(s[st] != s[en])
                return false;
            else{
                st++;
                en--;
            }
        }

        return true;
    }

    bool validPalindrome(string s) {
        int n = s.length();
        int st = 0, en = n-1;

        while(st < en){
            if(s[st] != s[en]){
                return check(s, st+1, en) || check(s, st, en-1);
            }
            else{
                st++;
                en--;
            }
        }

        return true;
    }
};