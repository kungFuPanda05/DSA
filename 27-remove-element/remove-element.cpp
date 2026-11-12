class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        int n = arr.size();
        const int inf = INT_MAX-100;
        int count = 0;
        for(int i=0; i<n; i++){
            if(arr[i]==val){
                count++;
                arr[i] = inf;
            }
        }
        sort(arr.begin(), arr.end());
        return n-count;
    }
};