class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int l=0;
        int h=n-1;
        while(h-l>1){
            int mid = l+(h-l)/2;
            if(arr[mid]>target){
                h=mid;
            }else{
                l=mid;
            }
        }
        if(arr[l]==target) return l;
        if(arr[h]==target) return h;
        return -1;
    }
};