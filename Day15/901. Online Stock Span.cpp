// https://leetcode.com/problems/online-stock-span/description/

class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>> st;
    int next(int price) {
        int ans = 1;
        while(st.size()>0 && st.top().first<=price)
        {
            ans+=st.top().second;
            st.pop();
        }
        st.push({price,ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */