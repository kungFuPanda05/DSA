class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int n = s.size();

        int i=0; int j=0;
        int ans = 0;
        while(j<n){
            m[s[j]]++;
            if(j-i+1==m.size()) {
                ans = max(ans, j-i+1);
            }else{
                while(i<=j && j-i+1!=m.size()){
                    m[s[i]]--;
                    if(m[s[i]]==0) m.erase(s[i]);
                    i++;
                }
                if(j-i+1==m.size()) ans = max(ans, j-i+1);
            }
            j++;
        }
        return ans;
    }
};