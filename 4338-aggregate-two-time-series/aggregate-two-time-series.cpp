class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        set <int> st;
        for(auto val: series1){
            st.insert(val[0]);
        }
        for(auto val: series2){
            st.insert(val[0]);
        }
        vector <vector <int>> ans;
        for(auto ts: st){
            vector <int> temp = {ts, INT_MIN};
            int idx1 = lower_bound(series1.begin(), series1.end(), temp) - series1.begin();
            int val1 = (idx1<series1.size())?series1[idx1][1]:0;

            int idx2 = lower_bound(series2.begin(), series2.end(), temp) - series2.begin();
            int val2 = (idx2<series2.size())?series2[idx2][1]:0;

            ans.push_back({ts, val1+val2});
        }
        return ans;
    }
};