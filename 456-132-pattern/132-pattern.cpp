class Solution {
public:
    int f(vector <int> &arr, int val){
        int l=0;
        int h=arr.size()-1;
        while(h-l>1){
            int mid = l+(h-l)/2;
            if(val>arr[mid]) h=mid;
            else l=mid;
        }
        if(arr[l]<val) return l;
        if(arr[h]<val) return h;
        return -1;
    }

    bool find132pattern(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector <int> left_g(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
            if(st.empty()) left_g[i] = -1;
            else left_g[i] = st.top();
            st.push(i);
        }
        vector <int> prefix(n, arr[0]);
        for(int i=1; i<n; i++){
            prefix[i] = min(prefix[i-1], arr[i]);
        }
        for(int i=2; i<n; i++){
            int i1 = f(prefix, arr[i]);
            int i2 = left_g[i];
            int i3 = i;
            // cout<<'i = '<<i<<" i1 = "<<i1<<" i2 = "<<i2<<" i3 = "<<i3<<endl;
            if(i1>=0 && i1<i2 && i2<i3 && arr[i1]<arr[i3] && arr[i3]<arr[i2]) return true;
        }
        return false;
    }
};