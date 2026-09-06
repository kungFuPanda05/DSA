class Solution {
public:
    int countGoodRotations(vector<int>& arr) {
        long long total=0;
        for(auto val: arr) total += val;
        long long sum=0;
        long long n = arr.size();
        long long i=0;
        long long j=0;
        long long ans = 0;
        while(j<n-1){
            sum += arr[j];
            if((j-i+1)==n/2){
                if(sum!=total-sum) ans++;
                sum -= arr[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};