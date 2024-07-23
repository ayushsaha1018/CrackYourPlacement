// TC : O(n), SC : O(n)

class Solution {
public:
    int calculate(string s) {
       int n = s.length();
       if(n == 0)
        return 0;
       
       int currNum = 0;
       char op = '+';
       stack<int> st;

       for(int i=0; i<n; i++){
            char currChar = s[i];
            if(isdigit(currChar))
                currNum = currNum*10 + (currChar - '0');
            
            if((!isdigit(currChar) && !iswspace(currChar)) || i == n-1){
                if(op == '-')
                    st.push(-currNum);
                else if(op == '+')
                    st.push(currNum);
                else if(op == '*'){
                    int stTop = st.top();
                    st.pop();
                    st.push(stTop * currNum);
                }
                else if(op == '/'){
                    int stTop = st.top();
                    st.pop();
                    st.push(stTop/currNum);
                }
                op = currChar;
                currNum = 0;
            }
       }

       int ans = 0;
       while(!st.empty()){
            ans += st.top();
            st.pop();
       }

       return ans;
    }
};