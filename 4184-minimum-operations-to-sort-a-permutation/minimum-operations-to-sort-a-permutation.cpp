class Solution {
public:
    const int inf = INT_MAX-100;

    int f(vector <int> arr){
        int n = arr.size();
        int i=1;
        while(i<n && arr[i]>=arr[i-1]) i++;
        if(i==n) return 0;
        int j=i+1;
        while(j<n && arr[j]>=arr[j-1]) j++;
        if(j!=n || arr[0]<arr[n-1]) return inf;

        return i;
    }

    vector <int> negate(vector <int> arr){
        vector <int> ans;
        for(auto val: arr) ans.push_back(-val);
        return ans;
    }

    int minOperations(vector<int>& nums) {
        int ans1 = f(nums);
        int ans2 = f(negate(nums))+1;

        reverse(nums.begin(), nums.end());
        int ans3 = 1+f(nums);
        int ans4 = 1+f(negate(nums))+1;

        int ans = min({ans1, ans2, ans3, ans4});
        return ans>=inf?-1:ans;
    }
};