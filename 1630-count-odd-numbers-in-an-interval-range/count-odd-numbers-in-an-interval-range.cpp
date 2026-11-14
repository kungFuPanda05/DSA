class Solution {
public:
    int f(int n){
        if(n&1){
            return (n+1)/2;
        }
        return n/2;
    }

    int countOdds(int low, int high) {
        if(low==high){
            return (low&1);
        }
        cout<<"f(high) = "<<f(high)<<endl;
        cout<<"f(low-1) = "<<f(low-1)<<endl;
        return f(high) - f(low-1);
    }
};