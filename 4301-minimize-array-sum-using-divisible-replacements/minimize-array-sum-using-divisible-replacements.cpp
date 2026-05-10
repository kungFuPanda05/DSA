class Solution {
public:
    long long minArraySum(vector<int>& arr) {
        long long ma = *max_element(arr.begin(), arr.end());
        vector <int> m(ma+1, -1);
        for(auto val: arr){
            if(val==1) {
                return arr.size();
            }
            for(long long i=1; val*i<=ma; i++){
                if(m[val*i]==-1){
                    m[val*i] = val;
                }else{
                    m[val*i] = min(m[val*i], val);
                }
            }
        }
        long long sum = 0;
        for(auto val: arr){
            sum += m[val];
        }
        return sum;
    }
};