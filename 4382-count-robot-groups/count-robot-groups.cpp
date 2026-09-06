class Solution {
public:
    void print(vector <int> arr){
        for(auto val: arr) cout<<val<<" ";
        cout<<endl;
    }

    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        vector <int> pos;
        vector <int> sp;
        int n = speed.size();

        for(int i=0; i<n; i++){
            if(pos.size()==0){
                pos.push_back(position[i]);
                sp.push_back(speed[i]);
            }else{
                if(position[i] - pos.back()<=distance) {
                    pos.pop_back();
                    sp.pop_back();
                }

                pos.push_back(position[i]);
                sp.push_back(speed[i]);
            }
        }
        position = pos;
        speed = sp;
        // print(position);
        // print(speed);

        stack <int> st;
        int i=0;
        n = speed.size();
        while(i<n){
            if(st.empty()) st.push(i);
            else{
                while(!st.empty() && speed[st.top()]>speed[i]) st.pop();
                st.push(i);
            }
            i++;
        }
        return st.size();
    }
};