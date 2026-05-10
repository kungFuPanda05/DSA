class Solution {
public:
    bool isLower(char ch){
        return (ch>='a' && ch<='z');
    }

    unordered_map <string, int> split(string s){
        string temp;
        unordered_map <string, int> m;
        int i=0;
        int n=s.size();
        while(i<n){
            int j=i;
            while(isLower(s[j]) || (s[j]=='-' && j-1>=0 && j+1<n && isLower(s[j-1]) && isLower(s[j+1]))) {
                temp += s[j];
                j++;
            } 
            if(!isLower(s[i])){
                i++;
                continue;
            }else{
                m[temp]++;
                temp="";
                i=j;
            }
        }
        return m;
    }

    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s;
        for(auto val: chunks) s += val;
        unordered_map<string, int> m = split(s);
        vector <int> ans;
        for(auto val: queries){
            ans.push_back(m[val]);
        }
        return ans;
    }
};