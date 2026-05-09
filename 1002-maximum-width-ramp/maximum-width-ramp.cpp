class Solution {
public:
    int f(vector <int> &arr, int val){
        int n = arr.size();
        int l=0;
        int h=n-1;
        while(h-l>1){
            int mid = l+(h-l)/2;
            if(arr[mid]>=val) l=mid;
            else h=mid;
        }
        if(arr[h]>=val) return h;
        if(arr[l]>=val) return l;
        return -1;
    }
    void print(vector <int> arr){
        for(auto val: arr) cout<<val<<" ";
        cout<<endl;
    }

    int maxWidthRamp(vector<int>& arr) {
        int n = arr.size();
        vector <int> right(n, arr.back());
        for(int i=n-2; i>=0; i--){
            right[i] = max(right[i+1], arr[i]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            int idx = f(right, arr[i]);
            cout<<"i = "<<i<<" idx = "<<idx<<endl;
            ans = max(ans, idx-i);
        }
        return ans;
    }
};