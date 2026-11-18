class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            if(arr[i]==1) count++;
            else count=0;
            ans = max(ans, count);
        }
        return ans;
    }
};