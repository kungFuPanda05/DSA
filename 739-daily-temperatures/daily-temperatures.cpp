class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector <int> ans(n);
        stack <int> st;
        int j=n-1;
        while(j>=0){
            while(!st.empty() and temp[st.top()]<=temp[j]) st.pop();
            if(st.empty()) ans[j] = 0;
            else ans[j] = st.top()-j;
            st.push(j--);
        }
        return ans;
    }
};