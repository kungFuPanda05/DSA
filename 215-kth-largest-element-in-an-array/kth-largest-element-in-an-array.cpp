class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int ma=INT_MIN;
        int mi=INT_MAX;
        for(auto val: nums) ma=max(ma, val), mi=min(mi, val);
        vector <int> bkt(ma-mi+1, 0);
        for(auto val: nums) bkt[val-mi]++;
        for(int i=ma; i>=mi; i--){
            k -= bkt[i-mi];
            if(k<=0) return i;
        }
        return -1;
    }
};