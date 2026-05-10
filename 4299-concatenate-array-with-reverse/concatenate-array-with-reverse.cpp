class Solution {
public:
    vector<int> concatWithReverse(vector<int>& arr) {
        int n = arr.size();
        for(int i=n-1; i>=0; i--) arr.push_back(arr[i]);
        return arr;
    }
};