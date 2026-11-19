class Solution {
public:
    const long long mod = 1e9+7;

    long long bn(long long a, long long b){
        if(b<0) return 1;
        if(b==0) return 1;
        long long binary = bn(a, b/2);
        if(b%2==0) return (binary*binary)%mod;
        return (a*binary*binary)%mod;
    }

    int countGoodNumbers(long long n) {
        if((n%2)==0) return (bn(5, n/2)*bn(4, n/2))%mod;
        return (bn(5, n/2+1)*bn(4, n/2))%mod;
    }
};