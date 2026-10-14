class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans;
        while(num--){
            int val = min(9, sum);
            sum -= val;
            ans += char(val+'0');
        }
        return sum==0?ans:"";
    }
};