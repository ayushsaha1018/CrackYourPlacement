// TC : O(2^n), SC : O(2^n)

class Solution {
public:
    vector<string> res;
    bool valid(string s){
        int open = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(')
                open++;
            else
                open--;
            
            if(open < 0)
                return false;
        }

        return open == 0;
    }
    void solve(int n, string t) {
        if (t.length() == 2*n) {
            if(valid(t))
                res.push_back(t);
            return;
        }

        t += '(';
        solve(n, t);
        t.pop_back();

        t += ')';
        solve(n, t);
        t.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        solve(n, "");
        return res;
    }
};