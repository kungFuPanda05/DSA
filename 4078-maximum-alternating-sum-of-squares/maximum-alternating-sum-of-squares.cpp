class Solution {
public:
    long long maxAlternatingSum(vector<int>& arr) {
        long long n = arr.size();
        long long sum = 0;
        for(auto &val: arr){
            val = val*val;
        }

        for(auto val: arr) sum += val;
        sort(arr.begin(), arr.end());

        long long temp = 0;
        for(long long i=0; i<n/2; i++){
            temp += arr[i];
        }
        return sum-2*temp;
    }
};