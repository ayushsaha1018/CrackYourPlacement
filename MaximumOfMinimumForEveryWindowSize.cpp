class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector<int> getNSL(int arr[], int n){
        stack<int> st;
        vector<int> res(n, -1);
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            if(!st.empty())
                res[i] = st.top();
            
            st.push(i);
        }
        
        return res;
    }
    
    vector<int> getNSR(int arr[], int n){
        stack<int> st;
        vector<int> res(n, n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            if(!st.empty())
                res[i] = st.top();
            
            st.push(i);
        }
        
        return res;
    }
    
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);
        
        vector<int> ans(n+1);
        for(int i=0; i<n; i++){
            int length = NSR[i] - NSL[i] - 1;
            ans[length] = max(ans[length], arr[i]);
        }
        
        for(int i=n-1; i>=1; i--){
            ans[i] = max(ans[i], ans[i+1]);
        }
        
        ans.erase(ans.begin());
        return ans;
    }
};