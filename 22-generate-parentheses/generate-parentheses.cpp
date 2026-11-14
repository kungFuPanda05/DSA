class Solution {
public:
    vector <string> ans;
    string temp;

    void f(int n, int br){

        if(n==0 && br==0){
            ans.push_back(temp);
            return;
        }
        if(n<0 || br<0) return;
        temp += '(';
        f(n-1, br+1);
        temp.pop_back();

        if(br>0) {
            temp += ')';
            f(n, br-1);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        f(n, 0);
        return ans;
    }
};