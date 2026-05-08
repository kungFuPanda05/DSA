class StockSpanner {
public:
    stack <int> st;
    vector <int> arr;
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        while(!st.empty() && arr[st.top()]<=price) st.pop();
        int idx;
        if(st.empty()) idx = -1;
        else idx = st.top();
        st.push(arr.size()-1);
        return arr.size()-idx-1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */