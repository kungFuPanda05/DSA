class Solution {
public:
    bool isSubtract(char ch1, char ch2){
        if(ch1=='I' && (ch2=='V' || ch2=='X')) return true;
        if(ch1=='X' && (ch2=='L' || ch2=='C')) return true;
        if(ch1=='C' && (ch2=='D' || ch2=='M')) return true;
        return false;
    }

    int num(char ch){
        if(ch=='I') return 1;
        if(ch=='V') return 5;
        if(ch=='X') return 10;
        if(ch=='L') return 50;
        if(ch=='C') return 100;
        if(ch=='D') return 500;
        if(ch=='M') return 1000;
        return 0;
    }

    int romanToInt(string s) {
        int ans = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            bool isNeg = false;
            if(i+1<n){
                isNeg = isSubtract(s[i], s[i+1]);
            }
            int number = num(s[i]);
            if(isNeg) number = -number;
            ans += number;
        }
        return ans;
    }
};