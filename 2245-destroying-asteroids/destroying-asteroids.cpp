class Solution {
public:
    bool asteroidsDestroyed(int Mass, vector<int>& arr) {
        multiset<long long> st;
        for(auto val: arr){
            st.insert(val);
        }
        long long mass = Mass;
        while(st.size()){
            auto it = st.upper_bound(mass);
            if(it==st.begin()) return false;
            it--;
            mass += *it;
            st.erase(it);
        }
        return true;
    }
};