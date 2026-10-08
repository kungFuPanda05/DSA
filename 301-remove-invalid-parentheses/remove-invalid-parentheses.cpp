class Solution {
public:
    set <string> ans;
    string s;
    int n;
    int maxLen;

    void f(int i, int br, string temp){

        if(i==n && br==0 && temp.size()==maxLen){
            ans.insert(temp);
            return;
        }
        if(br<0 || i==n || temp.size()>maxLen) return;

        if(s[i]!='(' && s[i]!=')') {
            f(i+1, br, temp+s[i]);
        }

        if(s[i]=='(') f(i+1, br+1, temp+s[i]);
        if(s[i]==')') f(i+1, br-1, temp+s[i]);

        f(i+1, br, temp);

    }

    void print(vector <int> arr){
        for(auto val: arr) cout<<val<<" ";
        cout<<endl;
    }

    int maxNum(string s){
        int n = s.size();

        stack <int> st;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')') {
                if(st.empty()) ans++;
                else st.pop();
            }
        }
        return s.size() - (ans + st.size());
    }

    vector<string> removeInvalidParentheses(string S) {
        s = S;
        n = s.size();
        maxLen = maxNum(s);


        f(0, 0, "");

        int ma = 0;
        for(auto val: ans){
            if(val.size()>ma) ma = val.size();
        }
        vector <string> check;
        for(auto val: ans){
            if(val.size()==ma) check.push_back(val);
        }
        return check;
    }
};