class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        
        int ans=INT_MAX-100;
        int total = 0;
        for(auto val: arr) total += val;

        int i=0;
        int j=0;
        int n = arr.size();
        int sz = n-k;
        if(n==k) return total;
        int sum=0;
        while(j<n){
            sum += arr[j];
            if(j-i+1==sz){
                ans = min(ans, sum);
                sum -= arr[i];
                i++;
            }
            j++;
        }
        return total-ans;
    }
};