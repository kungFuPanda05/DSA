class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int ans = 0;
        string og = s;
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                int count = 0;
                for(int j=i; j<n; j++){
                    count += (s[j]=='1');
                }
                for(int j=i; count>1 && j<n; j++){
                    if(s[j]=='1') {
                        s[j] = '0';
                        count--;
                        ans++;
                    }
                }
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(s[i]=='0'){
                int count = 0;
                for(int j=i; j>=0; j--){
                    count += (s[j]=='1');
                }
                for(int j=i; count>1 && j>=0; j--){
                    if(s[j]=='1') {
                        s[j] = '0';
                        count--;
                        ans++;
                    }
                }
                break;
            }
        }
        int occ = 1;
        int ans2 = 0;
        s = og;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                occ++;
                if(occ==2){
                    int count = 0;
                    for(int j=i; j<n; j++){
                        count += (s[j]=='0');
                    }
                    for(int j=i; count>=1 && j<n; j++){
                        if(s[j]=='0') {
                            s[j] = '1';
                            count--;
                            ans2++;
                        }
                    }
                    break;
                }
            }
        }
        
        occ=1;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='1'){
                occ++;
                if(occ==2){
                    int count = 0;
                    for(int j=i; j>=0; j--){
                        count += (s[j]=='0');
                    }
                    for(int j=i; count>=1 && j>=0; j--){
                        if(s[j]=='0') {
                            s[j] = '1';
                            count--;
                            ans2++;
                        }
                    }
                    break;
                }
            }
        }
        
        return min(ans, ans2);
    }
};