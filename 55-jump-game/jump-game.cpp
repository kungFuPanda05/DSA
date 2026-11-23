class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n = arr.size();
        int ma=0;
        for(int i=0; i<n; i++){
            if(i==n-1) return true;
            ma = max(ma, i+arr[i]);
            if(i>=ma) return false;
        }
        return true;
    }
};