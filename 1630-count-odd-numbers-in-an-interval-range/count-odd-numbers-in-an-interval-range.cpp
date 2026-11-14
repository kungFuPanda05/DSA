class Solution {
public:
    int f(int n){
        if(n&1){
            return (n+1)/2;
        }
        return n/2;
    }

    int countOdds(int low, int high) {
        return f(high) - f(low-1);
    }
};