// TC : O(n), SC : O(n)

class Solution {
public:
    string solve(string &s){
        string t = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] == '#'){
                if(t.length() > 0)
                    t.pop_back();
            }
            else{
                t.push_back(s[i]);
            }
        }

        return t;
    }

    bool backspaceCompare(string s, string t) {
        s = solve(s);
        t = solve(t);

        cout<<s<<" "<<t<<endl;

        return s == t;
    }
};