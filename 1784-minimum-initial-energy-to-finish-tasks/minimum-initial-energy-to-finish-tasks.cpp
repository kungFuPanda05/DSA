class Solution {
public:
    vector <vector <int>> arr;
    bool f(int energy){
        for(auto val: arr){
            if(energy<val[1]) return false;
            energy -= val[0];
        }
        return true;
    }
    static bool cmp(vector <int> &a, vector <int> &b){
        return (a[1]-a[0]>b[1]-b[0]);
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        arr = tasks;
        int n = arr.size();
        sort(arr.begin(), arr.end(), cmp);
        int ma = -1;
        for(auto val: arr) ma = max(ma, val[0]);
        int l=0;
        int h=ma*(n+1)+10001;
        while(h-l>1){
            int mid = l+(h-l)/2;
            if(f(mid)) h=mid;
            else l=mid;
        }
        if(f(l)) return l;
        return h;
    }
};