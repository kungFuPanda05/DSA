class Solution {
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector <int>> ans;
        int n = arr.size();
        for(int num=0; num<pow(2, n); num++){
            vector <int> temp;
            for(int i=0; i<n; i++){
                if(num&(1<<i)) temp.push_back(arr[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};