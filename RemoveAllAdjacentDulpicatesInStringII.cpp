class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int n = s.length();
        for(int i=0; i<n; i++){
            int cnt = 1;
            if(!st.empty() && st.top().first == s[i])
                st.top().second++;
            else
                st.push({s[i], 1});

            
            if(!st.empty() && st.top().second == k){
                    st.pop();
            }
        }

        string result;
        while(!st.empty()){
            result.append(st.top().second, st.top().first);
            st.pop();
        }
        
        reverse(result.begin(), result.end());

        return result;
    }
};