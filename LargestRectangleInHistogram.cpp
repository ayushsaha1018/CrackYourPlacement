// TC : O(n), SC : O(n)

class Solution {
public:
    vector<int> getNSL(vector<int>& heights, int n) {
        vector<int> res(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i])
                st.pop();
            if (!st.empty())
                res[i] = st.top();

            st.push(i);
        }

        return res;
    }

    vector<int> getNSR(vector<int>& heights, int n) {
        vector<int> res(n, n);
        stack<int> st;

        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (!st.empty())
                res[i] = st.top();

            st.push(i);
        }

        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> NSL = getNSL(heights, n);
        vector<int> NSR = getNSR(heights, n);

        int ans = 0;
        for(int i=0; i<n; i++){
            int l = heights[i];
            int b = NSR[i] - NSL[i] - 1;
            
            int area = l*b;
            ans = max(ans, area);
        }

        return ans;
    }
};