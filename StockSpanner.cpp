class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 0;
        while(!st.empty() && st.top().first <= price){
            cnt += st.top().second;
            st.pop();
        }

        st.push({price, cnt+1});
        return cnt+1;
    }
};