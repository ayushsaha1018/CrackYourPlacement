typedef unsigned long long ll;

class Solution {
public:
    vector<int> getNSL(vector<int>& arr, int n){
        vector<int> res(n, 0);
        stack<int> st;

        for(int i=0; i<n; i++){
            if(st.empty())
                res[i] = -1;
            else{
                while(!st.empty() && arr[st.top()] > arr[i])
                    st.pop();
                
                res[i] = st.empty() ? -1 : st.top();
            }

            st.push(i);
        }
        return res;
    }

    vector<int> getNSR(vector<int>& arr, int n){
        vector<int> res(n, 0);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            if(st.empty())
                res[i] = n;
            else{
                while(!st.empty() && arr[st.top()] >= arr[i])
                    st.pop();
                
                res[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }

        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        ll ans = 0;
        ll M = 1e9 + 7;
        for(int i=0; i<n; i++){
            ll d1 = i - NSL[i];
            ll d2 = NSR[i] - i;
            ll d = d1*d2;
            ll s = d*arr[i];
            ans = (ans + s)%M;
        }

        return ans;
    }
};