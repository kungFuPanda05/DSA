class Solution {
public:
    int maxWidthRamp(vector<int>& arr) {
        int n = arr.size();
        stack <int> st;
        for(int i=0; i<n; i++){
            if(st.empty() || arr[i]<arr[st.top()]) st.push(i);
        }
        int ans = 0;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                ans = max(ans, i-st.top());
                st.pop();
            }
        }
        return ans;
    }
};