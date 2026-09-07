class Solution {
public:
    const int inf = INT_MAX;
    int f(vector <int> arr){
        int n = arr.size();
        int p = 1;
        int ans = -inf;
        for(int i=0; i<n; i++){
            p *= arr[i];
            ans = max(ans, p);
            if(p==0) p=1;
        }
        return ans;
    }

    int maxProduct(vector<int>& nums) {
        int ans1 = f(nums);
        reverse(nums.begin(), nums.end());
        int ans2 = f(nums);
        return max(ans1, ans2);
    }
};